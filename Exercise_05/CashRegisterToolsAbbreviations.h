#ifndef CASH_REGISTER_TOOLS_ABBREVIATIONS_H

#include "time.h"

#define CASH_REGISTER_TOOLS_ABBREVIATIONS_H

typedef char* string;

typedef struct
{
	string name;
	float price;
}
PURCHASE_ITEM, * PURCHASE_ITEM_OBJECT, ** PURCHASE_ITEM_LIST;

typedef struct
{
	time_t date;
	PURCHASE_ITEM_LIST purchaseItems;
}
PURCHASE_RECEIPT, * PURCHASE_RECEIPT_OBJECT, ** PURCHASE_RECEIPT_LIST;

#endif