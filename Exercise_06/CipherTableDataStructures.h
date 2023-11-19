#ifndef CIPHER_TABLE_DATA_STRUCTURES_H

#define CIPHER_TABLE_DATA_STRUCTURES_H

#define STRING_TERMINATOR '\0'

typedef char** CIPHER_TABLE;
typedef char*** MASKED_CIPHER_TABLE;

typedef struct MaskedCipherTableItem
{
	MASKED_CIPHER_TABLE maskedTable;
	struct MaskedCipherTableItem* nextMaskedTable;
	struct MaskedCipherTableItem* previousMaskedTable;
}
MASKED_CIPHER_TABLE_LIST_ITEM, *MASKED_CIPHER_TABLE_LIST_ITEM_OBJECT;

#endif
