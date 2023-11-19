#ifndef CIPHER_TABLE_TESTS_H

#include "CipherTableDataStructures.h"
#include "stdbool.h"

#define CIPHER_TABLE_TESTS_H

#define TEST_SUCCESS true
#define TEST_FAILURE false

bool testFillCipherTable(CIPHER_TABLE cipherTable);
bool testCreateCipherTable(int rowsCount, int colsCount);
bool testCreateMaskedCipherTable(CIPHER_TABLE cipherTable);
bool testPushToCipherTableList(MASKED_CIPHER_TABLE maskedCipherTable);
bool testGetMaskedCipherTableBy(int index);


#endif