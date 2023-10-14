#define _CRT_SECURE_NO_WARNINGS 

#include "stdio.h"
#include "math.h"

int main() 
{
    FILE* input;
    char* inputFileName = "input.txt";

    input = fopen(inputFileName, "r");

    if (input == NULL)
    {
        printf("Chyba pri otevirani textoveho souboru %s pro cteni \n", inputFileName);
        return 1;
    }

    int width = 0;
    int height = 0;
    char parsedWidth[10] = { 0 };
    char parsedHeight[10] = { 0 };

    fgets(parsedWidth, sizeof(parsedWidth), input);
    sscanf(parsedWidth, "%d", &width);

    fgets(parsedHeight, sizeof(parsedHeight), input);
    sscanf(parsedHeight, "%d", &height);

    fclose(input);

    FILE* output;
    char* outputFileName = "vlajka.bin";

    output = fopen(outputFileName, "wb");

    if (output == NULL)
    {
        printf("Chyba pri otevirani binarniho souboru %s pro zapis \n", outputFileName);
        return 2;
    }

    char character;

    for (int x = 0; x < floor(height / 2); x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (y <= x)
            {
                character = '*';
                printf("%c", character);
                fwrite(&character, sizeof(char), 1, output);

            }
            else 
            {
                character = '-';
                printf("%c", character);
                fwrite(&character, sizeof(char), 1, output);
            }
        }
        
        character = '\n';
        printf("%c", character);
        fwrite(&character, sizeof(char), 1, output);
    }

    for (int i = 0; i < floor(height / 2); i++)
    {
        character = '*';
        printf("%c", character);
        fwrite(&character, sizeof(char), 1, output);
    }
    for (int i = 0; i < width - (int) floor(height / 2); i++)
    {
        character = '#';
        printf("%c", character);
        fwrite(&character, sizeof(char), 1, output);
    }
    character = '\n';
    printf("%c", character);
    fwrite(&character, sizeof(char), 1, output);

    for (int x = (int) floor(height / 2) - 1; x >= 0; x--)
    {
        for (int y = 0; y < width; y++)
        {
            if (y <= x)
            {
                character = '*';
                printf("%c", character);
                fwrite(&character, sizeof(char), 1, output);
            }
            else 
            {
                character = '+';
                printf("%c", character);
                fwrite(&character, sizeof(char), 1, output);
            }
        }

        character = '\n';
        printf("%c", character);
        fwrite(&character, sizeof(char), 1, output);
    }

    fclose(output);

    output = fopen(outputFileName, "rb");

    if (output == NULL)
    {
        printf("Chyba pri otevirani binarniho souboru %s pro cteni \n", outputFileName);
        return 3;
    }

    fseek(output, 0, SEEK_SET);

    printf("\nTest spravneho ulozeni do binarniho souboru: \n\n");

    int czechFlagArea = width * height;
    int newlinesCharsCount = height;

    for (int i = 0; i < czechFlagArea + newlinesCharsCount; i++)
    {
        fread(&character, sizeof(char), 1, output);
        printf("%c", character);
    }

    fclose(output);

    return 0;
}