#define _CRT_SECURE_NO_WARNINGS

#include "CashRegisterTools.h"

#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

int purchaseReceiptsCount = 0;
PURCHASE_RECEIPT_LIST purchaseReceiptsList = NULL;

PURCHASE_ITEM_OBJECT addPurchaseItem(const char name[], float price) 
{
	if (name == NULL || strlen(name) == 0 || price <= 0) return NULL;

	PURCHASE_ITEM newPurchaseItem;

	newPurchaseItem.name = (string) malloc((strlen(name) + 1) * sizeof(char));
	
	if (newPurchaseItem.name == NULL) return NULL;

	strcpy(newPurchaseItem.name, name);

	newPurchaseItem.price = price;

	PURCHASE_ITEM_OBJECT newPurchaseItemObject = (PURCHASE_ITEM_OBJECT) malloc(sizeof(PURCHASE_ITEM));
	if (newPurchaseItemObject == NULL) return NULL;

	*newPurchaseItemObject = newPurchaseItem;

	return newPurchaseItemObject;
}

PURCHASE_RECEIPT_OBJECT addPurchaseReceipt(PURCHASE_ITEM_LIST purchaseItems, time_t date)
{
	if (purchaseItems == NULL) return NULL;

	PURCHASE_ITEM_OBJECT purchasedItemsFirstItem = *(purchaseItems + 0);

	if (purchasedItemsFirstItem == NULL) return NULL;

	if (purchaseReceiptsList == NULL)
	{
		purchaseReceiptsList = (PURCHASE_RECEIPT_LIST) malloc(PURCHASE_RECEIPT_LIST_RESIZE_LIMIT * sizeof(PURCHASE_RECEIPT_OBJECT));
		if (purchaseReceiptsList == NULL) return NULL;
	}

	register int index;

	if (purchaseReceiptsCount % PURCHASE_RECEIPT_LIST_RESIZE_LIMIT == 0 && purchaseReceiptsCount != 0)
	{
		int divisionResult = purchaseReceiptsCount / PURCHASE_RECEIPT_LIST_RESIZE_LIMIT;

		int newPurchaseReceiptListCapacity = (divisionResult + 1) * PURCHASE_RECEIPT_LIST_RESIZE_LIMIT;

		PURCHASE_RECEIPT_LIST purchaseReceiptsListCopy =
			(PURCHASE_RECEIPT_LIST) malloc(newPurchaseReceiptListCapacity * sizeof(PURCHASE_RECEIPT_OBJECT));
		if (purchaseReceiptsListCopy == NULL) return NULL;

		index = 0;
		for (; index < purchaseReceiptsCount; index++) 
		{
			*(purchaseReceiptsListCopy + index) = *(purchaseReceiptsList + index);
			*(purchaseReceiptsList + index) = NULL;
		}
		free((void**) purchaseReceiptsList);

		purchaseReceiptsList = purchaseReceiptsListCopy;
	}

	PURCHASE_RECEIPT newPurchaseReceipt;

	register int purchaseReceiptItemsCount = 0;
	index = 0;
	while (*(purchaseItems + index) != NULL)
	{
		purchaseReceiptItemsCount++;
		index++;
	}

	newPurchaseReceipt.purchaseItems = (PURCHASE_ITEM_LIST) malloc((purchaseReceiptItemsCount + 1) * sizeof(PURCHASE_ITEM_OBJECT));
	if (newPurchaseReceipt.purchaseItems == NULL) return NULL;

	index = 0;
	for (; index < purchaseReceiptItemsCount; index++) 
	{
		*(newPurchaseReceipt.purchaseItems + index) = *(purchaseItems + index);
		*(purchaseItems + index) = NULL;
	}
	*(newPurchaseReceipt.purchaseItems + index) = NULL;
	free((void**) purchaseItems);

	newPurchaseReceipt.date = date;

	PURCHASE_RECEIPT_OBJECT newPurchaseReceiptObject = (PURCHASE_RECEIPT_OBJECT) malloc(sizeof(PURCHASE_RECEIPT));
	if (newPurchaseReceiptObject == NULL) return NULL;

	*newPurchaseReceiptObject = newPurchaseReceipt;
	purchaseReceiptsCount++;
	*(purchaseReceiptsList + (purchaseReceiptsCount - 1)) = newPurchaseReceiptObject;

	return newPurchaseReceiptObject;
}

float getChosenPurchaseReceiptTotalPrice(PURCHASE_RECEIPT_OBJECT purchaseReceipt) 
{
	if (purchaseReceipt == NULL) return -1;

	float totalPrice = 0;
	register int index = 0;
	register PURCHASE_ITEM_OBJECT purchaseReceiptItem = NULL;

	while ((purchaseReceiptItem = *(purchaseReceipt->purchaseItems + index)) != NULL)
	{
		totalPrice += purchaseReceiptItem->price;
		index++;
	}

	return totalPrice;
}

PURCHASE_RECEIPT_LIST getPurchaseReceiptsByPurchaseItemName(const char name[]) 
{
	if (name == NULL || strlen(name) == 0) return NULL;

	register PURCHASE_RECEIPT_OBJECT purchaseReceiptObject = NULL;
	register PURCHASE_ITEM_OBJECT purchaseReceiptItemObject = NULL;

	register bool wasReceiptItemWithMatchingNameFound;
	register int itemIndex;

	PURCHASE_RECEIPT_LIST foundReceipts =
		(PURCHASE_RECEIPT_LIST) malloc((purchaseReceiptsCount + 1) * sizeof(PURCHASE_RECEIPT_OBJECT));
	if (foundReceipts == NULL) return NULL;

	register int foundReceiptIndex = 0;

	for (register int index = 0; index < purchaseReceiptsCount; index++)
	{
		wasReceiptItemWithMatchingNameFound = false;
		purchaseReceiptObject = *(purchaseReceiptsList + index);
		
		itemIndex = 0;
		while ((purchaseReceiptItemObject = *(purchaseReceiptObject->purchaseItems + itemIndex)) != NULL && 
				wasReceiptItemWithMatchingNameFound == false)
		{
			wasReceiptItemWithMatchingNameFound = 
				strcmp(purchaseReceiptItemObject->name, name) == 0 ? true : false;

			itemIndex++;
		}

		if (wasReceiptItemWithMatchingNameFound == true) 
		{
			*(foundReceipts + foundReceiptIndex) = purchaseReceiptObject;
			foundReceiptIndex++;
		}
	}

	*(foundReceipts + foundReceiptIndex) = NULL;

	return foundReceipts;
}