#define _CRT_SECURE_NO_WARNINGS

#include "Main.h"

#include "CipherTools.h"
#include "IntegrationTests.h"

#include "stdio.h"
#include "stdlib.h"

int main()
{
	register int errorCode = runIntegrationTests();

	if (errorCode != 0) return errorCode;

	int inputArrayLength;
	int answer = -1;

	register bool isProgramRunning = true;
	register int successfullyParsedInputValues;
	register P_CHAR newCharArray;
	register P_PCHAR encodedCharArray;
	register int index;
	register bool errorOccured;

	while (isProgramRunning == true) 
	{
		displayMessage("Zadejte rozmer pole jako cele cislo: ");

		successfullyParsedInputValues = scanf("%d", &inputArrayLength);

		while ((getchar()) != '\n');

		if (successfullyParsedInputValues != 1) displayMessage("Nepodarilo se nacist rozmer pole jako cele cislo");
		else 
		{
			errorOccured = false;

			newCharArray = createCharArray(inputArrayLength);
			if (newCharArray == NULL)
			{
				errorOccured = true;
				displayCreateCharArrayMethodErrorMessage(newCharArray);
			}

			if (errorOccured == false) 
			{
				errorCode = fillCharArray(newCharArray);
				if (errorCode != 0)
				{
					errorOccured = true;
					displayFillCharArrayMethodErrorMessage(errorCode);
				}
			}

			encodedCharArray = NULL;
			if (errorOccured == false)
			{
				encodedCharArray = (P_PCHAR) malloc((inputArrayLength + 1) * sizeof(P_CHAR));
				if (encodedCharArray != NULL)
				{
					index = 0;
					for (; index < inputArrayLength; index++) *(encodedCharArray + index) = NULL;
				}

				errorCode = encodeCharArray(newCharArray, encodedCharArray);
				if (errorCode != 0)
				{
					errorOccured = true;
					displayEncodeCharArrayMethodErrorMessage(errorCode);
				}
			}

			if (errorOccured == false) 
			{
				errorCode = printEncodedCharArray(encodedCharArray);
				if (errorCode != 0)
				{
					errorOccured = true;
					displayPrintEncodedCharArrayMethodErrorMessage(errorCode);
				}
			}

			if (encodedCharArray != NULL)
			{
				index = 0;
				for (; index < inputArrayLength + 1; index++) *(encodedCharArray + index) = NULL;
			}
			free((void**)encodedCharArray);
			encodedCharArray = NULL;

			free((void*)newCharArray);
			newCharArray = NULL;
		}

		displayMessage("Chcete pokracovat? Pro ukonceni programu zadejte 0: ");

		scanf("%d", &answer);

		while ((getchar()) != '\n');

		if (answer == 0) isProgramRunning = false;
	}

	return 0;
}

static void displayMessage(const char message[])
{
	printf("\n%s\n", message);
}

static int runIntegrationTests() 
{
	bool testsResultsStates[TESTS_COUNT];
	int arrayLength = 8;
	register int index;

	testsResultsStates[0] = testCreateCharArray(arrayLength);
	testsResultsStates[0] == TEST_FAILURE ? displayMessage("test createCharArray() neuspesny") :
		displayMessage("test createCharArray() uspesny");
	if (testsResultsStates[0] == TEST_FAILURE) return 1;

	P_CHAR newCharArray = createCharArray(arrayLength);
	testsResultsStates[1] = testFillCharArray(newCharArray);
	testsResultsStates[1] == TEST_FAILURE ? displayMessage("test fillCharArray() neuspesny") :
		displayMessage("test fillCharArray() uspesny");
	if (testsResultsStates[1] == TEST_FAILURE)
	{
		free((void*)newCharArray);
		newCharArray = NULL;
		return 2;
	}

	P_PCHAR encodedCharArray = (P_PCHAR) malloc((arrayLength + 1) * sizeof(P_CHAR));
	if (encodedCharArray != NULL) for (register int index = 0; index < arrayLength; index++) *(encodedCharArray + index) = NULL;
	testsResultsStates[2] = testEncodeCharArray(newCharArray, encodedCharArray);
	testsResultsStates[2] == TEST_FAILURE ? displayMessage("test encodeCharArray() neuspesny") :
		displayMessage("test encodeCharArray() uspesny");
	if (testsResultsStates[2] == TEST_FAILURE)
	{
		if (encodedCharArray != NULL)
		{
			index = 0;
			for (; index < arrayLength + 1; index++) *(encodedCharArray + index) = NULL;
		}

		free((void**)encodedCharArray);
		encodedCharArray = NULL;

		free((void*)newCharArray);
		newCharArray = NULL;
		return 3;
	}

	testsResultsStates[3] = testPrintEncodedCharArray(encodedCharArray);
	testsResultsStates[3] == TEST_FAILURE ? displayMessage("test printEncodedCharArray() neuspesny") :
		displayMessage("test printEncodedCharArray() uspesny");
	if (testsResultsStates[3] == TEST_FAILURE) 
	{
		if (encodedCharArray != NULL)
		{
			index = 0;
			for (; index < arrayLength + 1; index++) *(encodedCharArray + index) = NULL;
		}

		free((void**)encodedCharArray);
		encodedCharArray = NULL;

		free((void*)newCharArray);
		newCharArray = NULL;
		return 4;
	}

	index = 0;
	for (; index < arrayLength + 1; index++) *(encodedCharArray + index) = NULL;
	free((void**) encodedCharArray);
	encodedCharArray = NULL;

	free((void*) newCharArray);
	newCharArray = NULL;

	return 0;
}