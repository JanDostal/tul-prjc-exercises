#ifndef CASH_REGISTER_TOOLS_H

#include "CashRegisterToolsAbbreviations.h"

#define CASH_REGISTER_TOOLS_H

#define PURCHASE_RECEIPT_LIST_RESIZE_LIMIT 2

PURCHASE_ITEM_OBJECT addPurchaseItem(const char name[], float price);
PURCHASE_RECEIPT_OBJECT addPurchaseReceipt(PURCHASE_ITEM_LIST purchaseItems, time_t date);

float getChosenPurchaseReceiptTotalPrice(PURCHASE_RECEIPT_OBJECT purchaseReceipt);
PURCHASE_RECEIPT_LIST getPurchaseReceiptsByPurchaseItemName(const char name[]);

#endif
