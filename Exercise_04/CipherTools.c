#include "CipherTools.h"

#include "stdlib.h"
#include "stdio.h"

P_CHAR createCharArray(int arrayLength) 
{
	if (arrayLength < 1 || arrayLength > 26) return NULL;

	P_CHAR newCharArray = (P_CHAR) malloc((arrayLength + 1) * sizeof(char));

	if (newCharArray == NULL) return NULL;

	*(newCharArray + arrayLength) = STRING_TERMINATOR;

	return newCharArray;
}

int fillCharArray(P_CHAR existingCharArray)
{
	if (existingCharArray == NULL) return ARRAY_NOT_ALLOCATED_ERROR_CODE;
	
	if (*(existingCharArray + 0) == STRING_TERMINATOR) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	register int index = 0;
	register int arrayLength = 0;

	while (*(existingCharArray + index) != STRING_TERMINATOR)
	{
		index++;
		arrayLength++;
	}

	if (arrayLength > 26) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	register char generatedChar = 'a';
	index = 0;

	for (; index < arrayLength; index++, generatedChar++) *(existingCharArray + index) = generatedChar;

	return 0;
}

int encodeCharArray(P_CHAR originalCharArray, P_PCHAR encodedCharArray)
{
	if (originalCharArray == NULL || encodedCharArray == NULL) return ARRAY_NOT_ALLOCATED_ERROR_CODE;

	if (*(originalCharArray + 0) == STRING_TERMINATOR || *(encodedCharArray + 0) != NULL) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	register char originalCharArrayCurrentChar;
	register P_CHAR encodedCharArrayCurrentPointer;

	register int index = 0;
	register int arrayLength = 0;

	do
	{
		arrayLength++;
		index++;

		originalCharArrayCurrentChar = *(originalCharArray + index);
		encodedCharArrayCurrentPointer = *(encodedCharArray + index);
	}
	while (originalCharArrayCurrentChar != STRING_TERMINATOR && encodedCharArrayCurrentPointer == NULL);

	if (arrayLength > 26) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	if ((originalCharArrayCurrentChar == STRING_TERMINATOR && encodedCharArrayCurrentPointer == NULL) ||
		(originalCharArrayCurrentChar != STRING_TERMINATOR && encodedCharArrayCurrentPointer != NULL)) return ARRAYS_LENGTH_NOT_SAME_ERROR_CODE;

	register int leftElementIndex, rightSideIndex;

	for (leftElementIndex = 0, rightSideIndex = arrayLength - 1; leftElementIndex < rightSideIndex; leftElementIndex++, rightSideIndex--)
	{
		*(encodedCharArray + leftElementIndex) = (originalCharArray + rightSideIndex);
		*(encodedCharArray + rightSideIndex) = (originalCharArray + leftElementIndex);
	}

	if (leftElementIndex == rightSideIndex) *(encodedCharArray + leftElementIndex) = (originalCharArray + leftElementIndex);

	*(encodedCharArray + arrayLength) = (originalCharArray + arrayLength);

	return 0;
}

int printEncodedCharArray(P_PCHAR encodedCharArray)
{
	if (encodedCharArray == NULL) return ARRAY_NOT_ALLOCATED_ERROR_CODE;

	P_CHAR encodedCharArrayFirstPointer = *(encodedCharArray + 0);

	if (encodedCharArrayFirstPointer != NULL && 
		*(encodedCharArrayFirstPointer + 0) == STRING_TERMINATOR) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	register P_CHAR encodedCharArrayCurrentPointer;

	register int index = 0;
	register int arrayLength = 0;

	while ((encodedCharArrayCurrentPointer = *(encodedCharArray + index)) != NULL && 
		   *(encodedCharArrayCurrentPointer + 0) != STRING_TERMINATOR)
	{
		arrayLength++;
		index++;
	}

	if (encodedCharArrayCurrentPointer == NULL) return ARRAY_NOT_FILLED_ERROR_CODE;

	if (arrayLength > 26) return ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE;

	index = 0;

	printf("\n");

	for (; index < arrayLength; index++) 
	{
		encodedCharArrayCurrentPointer = *(encodedCharArray + index);
		printf("%c", *(encodedCharArrayCurrentPointer + 0));
	}

	printf("\n");

	return 0;
}

void displayCreateCharArrayMethodErrorMessage(P_CHAR createdCharArray) 
{
	if (createdCharArray == NULL) 
	{
		printf("Vstupni parametr arrayLength neni v rozsahu 1 az 26 nebo se nepodarilo alokovat pole u funkce createCharArray()\n");
	}
}

void displayFillCharArrayMethodErrorMessage(int errorCode)
{
	switch (errorCode)
	{
		case ARRAY_NOT_ALLOCATED_ERROR_CODE:
			printf("Vstupni parametr existingCharArray jako pole neni alokovano u funkce fillCharArray()\n");
			break;
		case ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE:
			printf("Vstupni parametr existingCharArray jako pole musi delku mezi 1 az 26 u funkce fillCharArray()\n");
			break;
	}
}

void displayEncodeCharArrayMethodErrorMessage(int errorCode) 
{
	switch (errorCode)
	{
		case ARRAY_NOT_ALLOCATED_ERROR_CODE:
			printf("Vstupni parametry originalCharArray a encodedCharArray jako pole musi byt obe alokovany u funkce encodeCharArray()\n");
			break;
		case ARRAYS_LENGTH_NOT_SAME_ERROR_CODE:
			printf("Vstupni parametry originalCharArray a encodedCharArray jako pole nemaji stejnou delku u funkce encodeCharArray()\n");
			break;
		case ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE:
			printf("Vstupni parametry originalCharArray a encodedCharArray jako pole musi mit obe delky v rozsahu 1 az 26 u funkce encodeCharArray()\n");
			break;
	}
}

void displayPrintEncodedCharArrayMethodErrorMessage(int errorCode) 
{
	switch (errorCode)
	{
		case ARRAY_NOT_ALLOCATED_ERROR_CODE:
			printf("Vstupni parametr encodedCharArray jako pole musi byt alokovano u funkce printEncodedCharArray()\n");
			break;
		case ARRAY_LENGTH_NOT_IN_RANGE_ERROR_CODE:
			printf("Vstupni parametr encodedCharArray jako pole musi mit delku v rozsahu 1 az 26 u funkce printEncodedCharArray()\n");
			break;
		case ARRAY_NOT_FILLED_ERROR_CODE:
			printf("Vstupni parametr encodedCharArray jako pole musi byt plne naplnene u funkce printEncodedCharArray()\n");
			break;
	}
}