#include "CipherTableTests.h"

#include "CipherTableListTools.h"
#include "CipherTableTools.h"
#include "stdlib.h"

bool testFillCipherTable(CIPHER_TABLE cipherTable) 
{
	if (cipherTable == NULL) return TEST_FAILURE;

	register int rowIndex = 0;
	register int colIndex;
	register char charGenerator;

	while (*(cipherTable + rowIndex) != NULL)
	{
		charGenerator = 'a';

		colIndex = 0;
		while (*(*(cipherTable + rowIndex) + colIndex) != STRING_TERMINATOR)
		{
			*(*(cipherTable + rowIndex) + colIndex) = charGenerator;

			charGenerator++;
			colIndex++;
		}

		rowIndex++;
	}

	return TEST_SUCCESS;
}

bool testCreateCipherTable(int rowsCount, int colsCount) 
{
	CIPHER_TABLE table = createCipherTable(rowsCount, colsCount);

	if (table == NULL) return TEST_FAILURE;

	register int rowIndex = 0;
	while (*(table + rowIndex) != NULL)
	{
		free((void*) *(table + rowIndex));
		*(table + rowIndex) = NULL;

		rowIndex++;
	}

	free((void**) table);
	table = NULL;

	return TEST_SUCCESS;
}

bool testCreateMaskedCipherTable(CIPHER_TABLE cipherTable) 
{
	MASKED_CIPHER_TABLE maskedTable = createMaskedCipherTable(cipherTable);

	if (maskedTable == NULL) return TEST_FAILURE;

	register int rowIndex = 0;
	while (*(maskedTable + rowIndex) != NULL)
	{
		free((void**) *(maskedTable + rowIndex));
		*(maskedTable + rowIndex) = NULL;

		rowIndex++;
	}

	free((void***) maskedTable);
	maskedTable = NULL;

	return TEST_SUCCESS;
}

bool testPushToCipherTableList(MASKED_CIPHER_TABLE maskedCipherTable) 
{
	bool result = pushToCipherTableList(maskedCipherTable);

	if (result == false) return TEST_FAILURE;

	return TEST_SUCCESS;
}

bool testGetMaskedCipherTableBy(int index) 
{
	MASKED_CIPHER_TABLE maskedTable = getMaskedCipherTableBy(index);

	if (maskedTable == NULL) return TEST_FAILURE;

	return TEST_SUCCESS;
}