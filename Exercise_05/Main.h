#ifndef MAIN_H

#include "CashRegisterToolsAbbreviations.h"

#define MAIN_H

static void displayMessage(const char message[]);

static void displayPurchaseReceipt(PURCHASE_RECEIPT_OBJECT purchaseReceiptObject);

static void displayPurchaseReceiptItem(PURCHASE_ITEM_OBJECT purchaseReceiptItemObject);

static void displayPurchaseReceiptTotalPrice(float totalPrice);

static void displayPurchaseReceipts(PURCHASE_RECEIPT_LIST purchaseReceipts);

#endif
