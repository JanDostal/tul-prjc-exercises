#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>

int test_bin_values(FILE* file, int expected_int, float expected_float, double expected_double)
{
    if (file == NULL)
    {
        printf("Soubor bin chyba");
        return 1;
    }

    fseek(file, 0, SEEK_SET);

    int a = 0;
    float b = 0;
    double c = 0;

    fread(&a, sizeof(int), 1, file);
    fread(&b, sizeof(float), 1, file);
    fread(&c, sizeof(double), 1, file);

    fclose(file);

    printf("Nactena data: a = %d, b = %f, c = %f \n", a, b, c);

    if (expected_int != a)
    {
        printf("Neshoduje se int \n");
        return 2;
    }
    else if (expected_float != b)
    {
        printf("Neshoduje se float \n");
        return 2;
    }
    else if (expected_double != c)
    {
        printf("Neshoduje se double \n");
        return 2;
    }

    printf("Data se shoduji \n");

    return 0;
}

int test_text_values(FILE* file, int expected_int, float expected_float, double expected_double)
{
    if (file == NULL)
    {
        printf("Soubor text chyba");
        return 1;
    }

    int a = 0;
    float b = 0;
    double c = 0.0;

    while (fscanf(file, "%d %f %f", &a, &b, &c) != EOF)
        printf("Nactena data: %d %f %f \n", a, b, c);

    fclose(file);

    if (expected_int != a)
    {
        printf("Neshoduje se int \n");
        return 2;
    }
    else if (expected_float != b)
    {
        printf("Neshoduje se float \n");
        return 2;
    }
    else if (expected_double != c)
    {
        printf("Neshoduje se double \n");
        return 2;
    }

    printf("Data se shoduji \n");

    return 0;
}

int main() 
{
    // Write C code here

    FILE* bin;
    FILE* text;

    bin = fopen("SOUBOR.DAT", "wb+");
    text = fopen("SOUBOR.TXT", "w+");

    if (bin == NULL)
    {
        printf("chyba binarni");
        return 1;
    }

    if (text == NULL)
    {
        printf("chyba text");
        return 2;
    }

    int a = 0;
    float b = 0;
    double c = 0.0;

    printf("Zadejte 3 cisla a stisknete enter: \n");
    scanf("%d %f %f", &a, &b, &c);

    fprintf(text, "%d %f %f \n", a, b, c);

    fwrite(&a, sizeof(int), 1, bin);
    fwrite(&b, sizeof(float), 1, bin);
    fwrite(&c, sizeof(double), 1, bin);

    int info_text_code = test_text_values(text, a, b, c);

    int info_bin_code = test_bin_values(bin, a, b, c);

    return 0;
}