#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int binftest(char* fileName, int expectedInt, float expectedFloat, double expectedDouble)
{
    FILE* bin;

    bin = fopen(fileName, "rb");

    if (bin == NULL) return 1;

    fseek(bin, 0, SEEK_SET);

    int a = 0;
    float b = 0;
    double c = 0;

    fread(&a, sizeof(int), 1, bin);
    fread(&b, sizeof(float), 1, bin);
    fread(&c, sizeof(double), 1, bin);

    printf("Nactena data z binarniho souboru: a = %d, b = %f, c = %lf \n", a, b, c);

    fclose(bin);

    if (expectedInt != a) return 2;

    if (expectedFloat != b) return 3;

    if (expectedDouble != c) return 4;

    return 0;
}

int txtftest(char* fileName, int expectedInt, float expectedFloat, double expectedDouble)
{
    FILE* text;

    text = fopen(fileName, "r");

    if (text == NULL) return 1;

    int a = 0;
    float b = 0;
    double c = 0.0;

    while (fscanf(text, "%d %f %lf", &a, &b, &c) != EOF)
        printf("Nactena data z textoveho souboru: a = %d, b = %f, c = %lf \n", a, b, c);

    fclose(text);

    if (expectedInt != a) return 2;
    
    if (expectedFloat != b) return 3;
 
    if (expectedDouble != c) return 4;

    return 0;
}

int main() 
{
    // Write C code here

    int a = 0;
    float b = 0;
    double c = 0.0;

    printf("Zadejte 3 cisla a stisknete enter: \n");
    scanf("%d %f %lf", &a, &b, &c);

    printf("Zadana cisla: a = %d, b = %f, c = %lf \n", a, b, c);

    FILE* bin;
    FILE* text;

    char* binaryFileName = "SOUBOR.DAT";
    char* textFileName = "SOUBOR.TXT";

    bin = fopen(binaryFileName, "wb");

    if (bin == NULL)
    {
        printf("Chyba pri otevirani binarniho souboru %s pro zapis \n", binaryFileName);
        return 1;
    }

    text = fopen(textFileName, "w");

    if (text == NULL)
    {
        printf("Chyba pri otevirani textoveho souboru %s pro zapis \n", textFileName);
        fclose(bin);
        return 2;
    }

    fprintf(text, "%d %f %lf \n", a, b, c);

    fclose(text);

    fwrite(&a, sizeof(int), 1, bin);
    fwrite(&b, sizeof(float), 1, bin);
    fwrite(&c, sizeof(double), 1, bin);

    fclose(bin);

    int txtFileResult = txtftest(textFileName, a, b, c);

    switch (txtFileResult)
    {
        case 0:
            printf("Prectena data v textovem souboru se shoduji \n");
            break;
        case 1:
            printf("Chyba pri otevirani textoveho souboru %s pro cteni \n", textFileName);
            break;
        case 2:
            printf("V textovem souboru se neshoduje int, tedy promenna a \n");
            break;
        case 3:
            printf("V textovem souboru se neshoduje float, tedy promenna b \n");
            break;
        case 4:
            printf("V textovem souboru se neshoduje double, tedy promenna c \n");
            break;
    }

    int binFileResult = binftest(binaryFileName, a, b, c);

    switch (txtFileResult)
    {
        case 0:
            printf("Prectena data v binarnim souboru se shoduji \n");
            break;
        case 1:
            printf("Chyba pri otevirani binarniho souboru %s pro cteni \n", binaryFileName);
            break;
        case 2:
            printf("V binarnim souboru se neshoduje int, tedy promenna a \n");
            break;
        case 3:
            printf("V binarnim souboru se neshoduje float, tedy promenna b \n");
            break;
        case 4:
            printf("V binarnim souboru se neshoduje double, tedy promenna c \n");
            break;
    }

    return 0;
}