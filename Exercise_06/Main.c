#define _CRT_SECURE_NO_WARNINGS

#include "CipherTableTools.h"
#include "CipherTableTests.h"
#include "CipherTableListTools.h"

#include "stdio.h"

int main() 
{
	bool result = testCreateCipherTable(8, 9);
	if (result == TEST_FAILURE) 
	{
		printf("Test testCreateCipherTable() selhal\n");
		return 1;
	}

	CIPHER_TABLE t = createCipherTable(8, 9);

	result = testFillCipherTable(t);
	if (result == TEST_FAILURE)
	{
		printf("Test testFillCipherTable() selhal\n");
		return 2;
	}

	result = testCreateMaskedCipherTable(t);
	if (result == TEST_FAILURE)
	{
		printf("Test testCreateMaskedCipherTable() selhal\n");
		return 3;
	}

	MASKED_CIPHER_TABLE m = createMaskedCipherTable(t);
	MASKED_CIPHER_TABLE m2 = createMaskedCipherTable(t);
	MASKED_CIPHER_TABLE m3 = createMaskedCipherTable(t);
	MASKED_CIPHER_TABLE m4 = createMaskedCipherTable(t);

	printMaskedCipherTable(m);
	printMaskedCipherTable(m3);
	printMaskedCipherTable(m2);

	result = testPushToCipherTableList(m);
	if (result == TEST_FAILURE)
	{
		printf("Test testPushToCipherTableList() selhal\n");
		return 4;
	}

	pushToCipherTableList(m);
	pushToCipherTableList(m2);
	pushToCipherTableList(m3);
	pushToCipherTableList(m4);

	result = testGetMaskedCipherTableBy(2);
	if (result == TEST_FAILURE)
	{
		printf("Test testGetMaskedCipherTableBy() selhal\n");
		return 5;
	}

	MASKED_CIPHER_TABLE indexedTable = getMaskedCipherTableBy(2);
	MASKED_CIPHER_TABLE indexedTable2 = getMaskedCipherTableBy(1);

	printMaskedCipherTable(indexedTable);
	printMaskedCipherTable(indexedTable2);

	return 0;
}