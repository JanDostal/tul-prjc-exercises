#ifndef CIPHER_TABLE_LIST_TOOLS_H

#include "CipherTableDataStructures.h"

#define CIPHER_TABLE_LIST_TOOLS_H

void pushToCipherTableList(MASKED_CIPHER_TABLE maskedCipherTable);
MASKED_CIPHER_TABLE getMaskedCipherTableBy(int index);

#endif