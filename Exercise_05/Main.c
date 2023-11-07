#define _CRT_SECURE_NO_WARNINGS

#include "Main.h"

#include "CashRegisterTools.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int main()
{
	PURCHASE_ITEM_LIST items1 = (PURCHASE_ITEM_LIST) malloc((2 + 1) * sizeof(PURCHASE_ITEM_OBJECT));
	if (items1 == NULL) 
	{
		displayMessage("Nepodarilo se alokovat items1 jako seznam polozek uctenky");
		return 1;
	}

	PURCHASE_ITEM_LIST items2 = (PURCHASE_ITEM_LIST) malloc((2 + 1) * sizeof(PURCHASE_ITEM_OBJECT));
	if (items2 == NULL)
	{
		displayMessage("Nepodarilo se alokovat items2 jako seznam polozek uctenky");
		return 2;
	}

	PURCHASE_ITEM_LIST items3 = (PURCHASE_ITEM_LIST) malloc((2 + 1) * sizeof(PURCHASE_ITEM_OBJECT));
	if (items3 == NULL)
	{
		displayMessage("Nepodarilo se alokovat items3 jako seznam polozek uctenky");
		return 3;
	}

	PURCHASE_ITEM_OBJECT purchaseReceiptItemObject = NULL;

	purchaseReceiptItemObject = addPurchaseItem("rajce", 30);
	items1[0] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	purchaseReceiptItemObject = addPurchaseItem("mleko", 20);
	items1[1] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	items1[2] = NULL;

	purchaseReceiptItemObject = addPurchaseItem("syr", 22);
	items2[0] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	purchaseReceiptItemObject = addPurchaseItem("jablko", 15);
	items2[1] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	items2[2] = NULL;

	purchaseReceiptItemObject = addPurchaseItem("mleko", 10);
	items3[0] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	purchaseReceiptItemObject = addPurchaseItem("pizza", 4);
	items3[1] = purchaseReceiptItemObject == NULL ? NULL : purchaseReceiptItemObject;
	items3[2] = NULL;


	PURCHASE_RECEIPT_OBJECT receipt1 = addPurchaseReceipt(items1, 2500);
	if (receipt1 != NULL) displayMessage("Uctenka receipt1:");
	displayPurchaseReceipt(receipt1);

	PURCHASE_RECEIPT_OBJECT receipt2 = addPurchaseReceipt(items2, 250000);
	if (receipt2 != NULL) displayMessage("Uctenka receipt2:");
	displayPurchaseReceipt(receipt2);

	PURCHASE_RECEIPT_OBJECT receipt3 = addPurchaseReceipt(items3, 2500000);
	if (receipt3 != NULL) displayMessage("Uctenka receipt3:");
	displayPurchaseReceipt(receipt3);

	float receipt3Price = getChosenPurchaseReceiptTotalPrice(receipt3);
	if (receipt3Price > 0) displayMessage("Celkova cena uctenky receipt3:");
	displayPurchaseReceiptTotalPrice(receipt3Price);

	PURCHASE_RECEIPT_LIST foundReceipts = getPurchaseReceiptsByPurchaseItemName("pizza");
	if (foundReceipts != NULL) displayMessage("Nalezene uctenky s polozkami s nazvem pizza:");
	displayPurchaseReceipts(foundReceipts);

	return 0;
}

static void displayMessage(const char message[])
{
	if (message != NULL && strlen(message) != 0) printf("\n%s\n", message);
}

static void displayPurchaseReceipt(PURCHASE_RECEIPT_OBJECT purchaseReceiptObject)
{
	if (purchaseReceiptObject != NULL) 
	{
		displayMessage("Informace o uctence:");

		struct tm* purchaseReceiptDateInfo;
		purchaseReceiptDateInfo = gmtime(&purchaseReceiptObject->date);

		char outputText[20] = { 0 };
		sprintf(outputText, "%d. %d. %d", purchaseReceiptDateInfo->tm_mday,
			(purchaseReceiptDateInfo->tm_mon + 1), (purchaseReceiptDateInfo->tm_year + 1900));
		
		printf("datum uctenky: %s\n", outputText);
		
		displayMessage("Informace o polozkach uctenky:");

		register PURCHASE_ITEM_OBJECT purchaseReceiptItemObject = NULL;
		register int index = 0;
		while ((purchaseReceiptItemObject = *(purchaseReceiptObject->purchaseItems + index)) != NULL) 
		{
			displayPurchaseReceiptItem(purchaseReceiptItemObject);
			index++;
		}
	}
}

static void displayPurchaseReceiptItem(PURCHASE_ITEM_OBJECT purchaseReceiptItemObject)
{
	if (purchaseReceiptItemObject != NULL) 
	{
		displayMessage("Informace o polozce uctenky:");

		printf("nazev polozky: %s\n", purchaseReceiptItemObject->name);
		printf("cena polozky: %.2f KC\n", purchaseReceiptItemObject->price);
	}
}

static void displayPurchaseReceiptTotalPrice(float totalPrice) 
{
	if (totalPrice > 0)
	{
		char formattedPrice[50] = { 0 };
		sprintf(formattedPrice, "Celkova cena uctenky je %.2f KC", totalPrice);

		displayMessage(formattedPrice);
	}
}

static void displayPurchaseReceipts(PURCHASE_RECEIPT_LIST purchaseReceipts) 
{
	if (purchaseReceipts != NULL) 
	{
		register PURCHASE_RECEIPT_OBJECT purchaseReceiptObject = NULL;
		register int index = 0;
		while ((purchaseReceiptObject = *(purchaseReceipts + index)) != NULL)
		{
			displayPurchaseReceipt(purchaseReceiptObject);
			index++;
		}
	}
}