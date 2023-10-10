#include "IOManager.h"
#include "stdio.h"

int chosenGeometricShapeNumber = 0;
float circleDiameter = 0;
float rectangleSideA = 0;
float rectangleSideB = 0;
float triangleSideHeight = 0;
float triangleSide = 0;

int loadGeometricShape() 
{
	displayGeometricShapesMenu();

	int successCode = scanf("%d", &chosenGeometricShapeNumber);

	if (successCode != 1) 
	{
		return 1;
	}

	displayAdditionalMenu(chosenGeometricShapeNumber);

	successCode = loadAdditionalChoice(chosenGeometricShapeNumber);

	if (successCode != 1)
	{
		return 2;
	}

	return 0;
}

static void displayGeometricShapesMenu() 
{
	printf("Dostupn� volby pro v�b�r geometrick�ho tvaru: \n");
	printf("\n");

	printf("%-4s Kruh\n", "1.");
	printf("%-4s Obdeln�k\n", "2.");
	printf("%-4s Troj�heln�k\n", "3.");

	printf("Zadejte ��slo volby: \n");
}

static int loadAdditionalChoice(int chosenShape) 
{
	int successCode = 0;

	switch (chosenShape)
	{
		case CIRCLE:
			successCode = scanf("%f", &circleDiameter);
			break;
		case RECTANGLE:
			successCode = scanf("%f %f", &rectangleSideA, &rectangleSideB);
			break;
		case TRIANGULAR:
			successCode = scanf("%f %f", &triangleSide, &triangleSideHeight);
			break;
	}

	return successCode;
}

static void displayAdditionalMenu(int chosenShape) 
{
	switch (chosenShape) 
	{
		case CIRCLE:
			printf("Zadejte pr�m�r kruhu: \n");
			break;
		case RECTANGLE:
			printf("Zadejte ob� strany obdeln�ka (odd�leno mezerou): \n");
			break;
		case TRIANGULAR:
			printf("Zadejte stranu a v��ku strany troj�heln�ka (odd�leno mezerou): \n");
			break;
	}
}