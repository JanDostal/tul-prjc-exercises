#include "CipherTableListTools.h"

#include "stdlib.h"

MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT firstMaskedCipherTable = NULL;
MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT lastMaskedCipherTable = NULL;

int maskedCipherTablesCount = 0;

bool pushToCipherTableList(MASKED_CIPHER_TABLE maskedCipherTable) 
{
	if (maskedCipherTable == NULL) return false;

	MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT newMaskedCipherTableReference =
		(MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT) malloc(sizeof(MASKED_CIPHER_TABLE_LIST_ITEM));

	if (newMaskedCipherTableReference == NULL) return false;

	if (firstMaskedCipherTable == NULL) 
	{
		MASKED_CIPHER_TABLE_LIST_ITEM newMaskedCipherTable;

		newMaskedCipherTable.maskedTable = maskedCipherTable;
		newMaskedCipherTable.nextMaskedTable = NULL;
		newMaskedCipherTable.previousMaskedTable = NULL;

		*newMaskedCipherTableReference = newMaskedCipherTable;
		firstMaskedCipherTable = newMaskedCipherTableReference;
	}
	else 
	{
		MASKED_CIPHER_TABLE_LIST_ITEM newMaskedCipherTable;

		newMaskedCipherTable.maskedTable = maskedCipherTable;
		newMaskedCipherTable.nextMaskedTable = NULL;
		newMaskedCipherTable.previousMaskedTable = lastMaskedCipherTable;

		*newMaskedCipherTableReference = newMaskedCipherTable;
		lastMaskedCipherTable->nextMaskedTable = newMaskedCipherTableReference;
	}

	lastMaskedCipherTable = newMaskedCipherTableReference;
	maskedCipherTablesCount++;

	return true;
}

MASKED_CIPHER_TABLE getMaskedCipherTableBy(int index) 
{
	if ((index + 1) <= 0 || (index + 1) > maskedCipherTablesCount) return NULL;

	int tableIndexFromStart = index;
	int tableIndexFromEnd = maskedCipherTablesCount - (index + 1);

	MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT maskedCipherTableReference;

	if (tableIndexFromStart <= tableIndexFromEnd) 
	{
		maskedCipherTableReference = firstMaskedCipherTable;

		if (tableIndexFromStart != 0)
		{
			for (register int index = 1; index <= tableIndexFromStart; index++)
			{
				maskedCipherTableReference = maskedCipherTableReference->nextMaskedTable;
			}
		}
	}
	else 
	{
		maskedCipherTableReference = lastMaskedCipherTable;

		if (tableIndexFromStart != (maskedCipherTablesCount - 1))
		{
			for (register int index = 1; index <= tableIndexFromEnd; index++)
			{
				maskedCipherTableReference = maskedCipherTableReference->previousMaskedTable;
			}
		}
	}

	return maskedCipherTableReference->maskedTable;
}