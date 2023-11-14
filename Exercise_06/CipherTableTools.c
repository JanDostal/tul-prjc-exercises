#include "CipherTableTools.h"

#include "stdlib.h"
#include "stdbool.h"

CIPHER_TABLE createCipherTable(int rowsCount, int colsCount) 
{
	if (rowsCount <= 0 || colsCount <= 0) return NULL;

	CIPHER_TABLE cipherTable = (CIPHER_TABLE) malloc(rowsCount * sizeof(char*));

	if (cipherTable == NULL) return NULL;

	bool rowAllocationFailed = false;
	register int index = 0;

	for (; index < rowsCount && rowAllocationFailed == false; index++) 
	{
		*(cipherTable + index) = (char*) malloc(colsCount * sizeof(char));

		if (*(cipherTable + index) == NULL) rowAllocationFailed = true;
	}

	if (rowAllocationFailed == true) 
	{
		index--;

		for (; index >= 0; index--)
		{
			free(*(cipherTable + index));
			*(cipherTable + index) = NULL;
		}

		return NULL;
	}

	return cipherTable;
}

MASKED_CIPHER_TABLE createMaskedCipherTable(CIPHER_TABLE cipherTable) 
{

}

void printMaskedCipherTable(MASKED_CIPHER_TABLE maskedCipherTable) 
{

}