#include "IntegrationTests.h"

#include "CipherTools.h"

#include "stdlib.h"

bool testCreateCharArray(int arrayLength) 
{
	P_CHAR newCharArray = createCharArray(arrayLength);

	if (newCharArray == NULL) 
	{
		displayCreateCharArrayMethodErrorMessage(newCharArray);
		return TEST_FAILURE;
	}

	free((void*) newCharArray);
	newCharArray = NULL;

	return TEST_SUCCESS;
}

bool testFillCharArray(P_CHAR existingCharArray)
{
	int errorCode = fillCharArray(existingCharArray);

	if (errorCode != 0)
	{
		displayFillCharArrayMethodErrorMessage(errorCode);
		return TEST_FAILURE;
	}

	return TEST_SUCCESS;
}

bool testEncodeCharArray(P_CHAR originalCharArray, P_PCHAR encodedCharArray)
{
	int errorCode = encodeCharArray(originalCharArray, encodedCharArray);

	if (errorCode != 0)
	{
		displayEncodeCharArrayMethodErrorMessage(errorCode);
		return TEST_FAILURE;
	}

	return TEST_SUCCESS;
}

bool testPrintEncodedCharArray(P_PCHAR encodedCharArray)
{
	int errorCode = printEncodedCharArray(encodedCharArray);

	if (errorCode != 0)
	{
		displayPrintEncodedCharArrayMethodErrorMessage(errorCode);
		return TEST_FAILURE;
	}

	return TEST_SUCCESS;
}