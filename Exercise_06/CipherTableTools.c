#include "CipherTableTools.h"

#include "stdlib.h"
#include "stdbool.h"
#include "math.h"
#include "stdio.h"

CIPHER_TABLE createCipherTable(int rowsCount, int colsCount) 
{
	if (rowsCount <= 0 || colsCount <= 0) return NULL;

	CIPHER_TABLE cipherTable = (CIPHER_TABLE) malloc((rowsCount + 1) * sizeof(char*));

	if (cipherTable == NULL) return NULL;

	bool rowAllocationFailed = false;
	register int index = 0;

	for (; index < rowsCount && rowAllocationFailed == false; index++) 
	{
		*(cipherTable + index) = (char*) malloc((colsCount + 1) * sizeof(char));

		if (*(cipherTable + index) == NULL) rowAllocationFailed = true;

		*(*(cipherTable + index) + colsCount) = STRING_TERMINATOR;
	}

	if (rowAllocationFailed == true) 
	{
		index--;

		for (; index >= 0; index--)
		{
			free((void*) *(cipherTable + index));
			*(cipherTable + index) = NULL;
		}

		free((void**) cipherTable);
		cipherTable = NULL;

		return NULL;
	}

	*(cipherTable + index) = NULL;

	return cipherTable;
}

MASKED_CIPHER_TABLE createMaskedCipherTable(CIPHER_TABLE cipherTable) 
{
	if (cipherTable == NULL) return NULL;

	register int rowsCount = 0;
	while (*(cipherTable + rowsCount) != NULL)
	{
		rowsCount++;
	}

	MASKED_CIPHER_TABLE maskedCipherTable = (MASKED_CIPHER_TABLE) malloc((rowsCount + 1) * sizeof(char**));

	if (maskedCipherTable == NULL) return NULL;

	bool rowAllocationFailed = false;
	register int rowIndex = 0;
	register int colIndex;
	register int colsCount;

	for (; rowIndex < rowsCount && rowAllocationFailed == false; rowIndex++)
	{
		colsCount = 0;
		while (*(*(cipherTable + rowIndex) + colsCount) != STRING_TERMINATOR)
		{
			colsCount++;
		}

		*(maskedCipherTable + rowIndex) = (char**) malloc((colsCount + 1) * sizeof(char*));

		if (*(maskedCipherTable + rowIndex) == NULL)
		{
			rowAllocationFailed = true;
			continue;
		}

		for (colIndex = 0; colIndex < colsCount; colIndex++)
		{
			*(*(maskedCipherTable + rowIndex) + colIndex) = (*(cipherTable + rowIndex) + colsCount);
		}

		*(*(maskedCipherTable + rowIndex) + colIndex) = NULL;
	}

	int maskedCipherTableElementsCount = rowsCount * colsCount;
	int maskedCipherTableTwentyPercentsElementsCount = ceilf((float) (maskedCipherTableElementsCount * 20) / 100);

	int* maskedCipherTableElementsPositions = (int*) malloc(maskedCipherTableTwentyPercentsElementsCount * sizeof(int));

	if (rowAllocationFailed == true || maskedCipherTableElementsPositions == NULL)
	{
		rowIndex--;

		for (; rowIndex >= 0; rowIndex--)
		{
			free((void**) *(maskedCipherTable + rowIndex));
			*(maskedCipherTable + rowIndex) = NULL;
		}

		free((void***) maskedCipherTable);
		maskedCipherTable = NULL;

		free((void*) maskedCipherTableElementsPositions);
		maskedCipherTableElementsPositions = NULL;

		return NULL;
	}

	register int index;
	for (index = 0; index < maskedCipherTableTwentyPercentsElementsCount; index++) 
	{
		*(maskedCipherTableElementsPositions + index) = 0;
	}

	int randomPosition;
	register int placedPositionIndex;
	bool wasFound;

	register int chosenCol;
	register int chosenRow;

	for (index = 0; index < maskedCipherTableTwentyPercentsElementsCount; index++) 
	{
		randomPosition = (rand() % maskedCipherTableElementsCount) + 1;
		wasFound = false;

		for (placedPositionIndex = 0; placedPositionIndex < maskedCipherTableTwentyPercentsElementsCount && 
			wasFound == false; placedPositionIndex++)
		{
			if (*(maskedCipherTableElementsPositions + placedPositionIndex) == randomPosition) 
			{
				wasFound = true;
			}
		}

		if (wasFound == true) 
		{
			index--;
		}
		else 
		{
			chosenRow = randomPosition % colsCount == 0 ? randomPosition / colsCount : randomPosition / colsCount + 1;
			chosenCol = randomPosition % colsCount == 0 ? colsCount : randomPosition % colsCount;

			*(*(maskedCipherTable + (chosenRow - 1)) + (chosenCol - 1)) = (*(cipherTable + (chosenRow - 1)) + (chosenCol - 1));
			*(maskedCipherTableElementsPositions + index) = randomPosition;
		}
	}

	*(maskedCipherTable + rowIndex) = NULL;

	free((void*) maskedCipherTableElementsPositions);
	maskedCipherTableElementsPositions = NULL;

	return maskedCipherTable;
}

void printMaskedCipherTable(MASKED_CIPHER_TABLE maskedCipherTable) 
{
	if (maskedCipherTable == NULL) return;

	register int rowIndex = 0;
	register int colIndex;
	while (*(maskedCipherTable + rowIndex) != NULL)
	{
		colIndex = 0;
		while (*(*(maskedCipherTable + rowIndex) + colIndex) != NULL) 
		{
			if (*(*(*(maskedCipherTable + rowIndex) + colIndex)) != STRING_TERMINATOR)
			{
				printf("%c", *(*(*(maskedCipherTable + rowIndex) + colIndex)));
			}

			colIndex++;
		}

		rowIndex++;
	}

	printf("\n");
}