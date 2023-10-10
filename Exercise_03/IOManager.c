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
	printf("Dostupné volby pro výbìr geometrického tvaru: \n");
	printf("\n");

	printf("%-4s Kruh\n", "1.");
	printf("%-4s Obdelník\n", "2.");
	printf("%-4s Trojúhelník\n", "3.");

	printf("Zadejte èíslo volby: \n");
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
			printf("Zadejte prùmìr kruhu: \n");
			break;
		case RECTANGLE:
			printf("Zadejte obì strany obdelníka (oddìleno mezerou): \n");
			break;
		case TRIANGULAR:
			printf("Zadejte stranu a výšku strany trojúhelníka (oddìleno mezerou): \n");
			break;
	}
}