#ifndef CIPHER_TABLE_TOOLS_H

#include "CipherTableDataStructures.h"

#define CIPHER_TABLE_TOOLS_H
 
CIPHER_TABLE createCipherTable(int rowsCount, int colsCount);
MASKED_CIPHER_TABLE createMaskedCipherTable(CIPHER_TABLE cipherTable);
void printMaskedCipherTable(MASKED_CIPHER_TABLE maskedCipherTable);

#endif