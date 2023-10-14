#define _CRT_SECURE_NO_WARNINGS

#include "InputManager.h"
#include "stdio.h"

int chosenGeometricShapeNumber = 0;
double inputCircleDiameter = 0;
double inputRectangleSideA = 0;
double inputRectangleSideB = 0;
double inputTriangleSideHeight = 0;
double inputTriangleSide = 0;

int loadGeometricShapeData() 
{
	displayGeometricShapesMenu();

	int successfullyParsedValuesCount = loadChosenShapeNumber();

	int errorCode = checkChosenGeometricShapeNumberValidity(successfullyParsedValuesCount);

	if (errorCode != 0) 
	{
		return errorCode;
	}

	displayChosenShapeAdditionalDataMenu();

	successfullyParsedValuesCount = loadChosenShapeAdditionalData();

	errorCode = checkChosenGeometricShapeAdditionalDataValidity(successfullyParsedValuesCount);

	if (errorCode != 0) 
	{
		return errorCode;
	}

	return 0;
}

static int checkChosenGeometricShapeNumberValidity(int successfullyParsedValuesCount)
{
	if (successfullyParsedValuesCount != 1)
	{
		return GEOMETRIC_SHAPE_NUMBER_NOT_PARSED_ERROR_CODE;
	}

	if (chosenGeometricShapeNumber != CIRCLE && chosenGeometricShapeNumber != TRIANGLE && chosenGeometricShapeNumber != RECTANGLE)
	{
		return GEOMETRIC_SHAPE_NUMBER_NOT_VALID_ERROR_CODE;
	}

	return 0;
}

static int checkChosenGeometricShapeAdditionalDataValidity(int successfullyParsedValuesCount)
{
	switch (chosenGeometricShapeNumber)
	{
		case CIRCLE:

			if (successfullyParsedValuesCount != 1)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_PARSED_ERROR_CODE;
			}

			if (inputCircleDiameter <= 0)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_VALID_ERROR_CODE;
			}

			break;

		case RECTANGLE:

			if (successfullyParsedValuesCount != 2)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_PARSED_ERROR_CODE;
			}

			if (inputRectangleSideA <= 0 || inputRectangleSideB <= 0)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_VALID_ERROR_CODE;
			}

			break;

		case TRIANGLE:

			if (successfullyParsedValuesCount != 2)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_PARSED_ERROR_CODE;
			}

			if (inputTriangleSideHeight <= 0 || inputTriangleSide <= 0)
			{
				return GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_VALID_ERROR_CODE;
			}

			break;
	}

	return 0;
}

static void displayGeometricShapesMenu() 
{
	printf("\nDostupne volby pro vyber geometrickeho tvaru: \n");
	printf("\n");

	printf("%-4s Kruh\n", "1.");
	printf("%-4s Obdelnik\n", "2.");
	printf("%-4s Trojuhelnik\n", "3.");

	printf("\n");
	printf("Zadejte cislo volby: \n");
}

static int loadChosenShapeAdditionalData()
{
	int successfullyParsedValuesCount = 0;

	switch (chosenGeometricShapeNumber)
	{
		case CIRCLE:
			successfullyParsedValuesCount = scanf("%lf", &inputCircleDiameter);
			break;
		case RECTANGLE:
			successfullyParsedValuesCount = scanf("%lf %lf", &inputRectangleSideA, &inputRectangleSideB);
			break;
		case TRIANGLE:
			successfullyParsedValuesCount = scanf("%lf %lf", &inputTriangleSide, &inputTriangleSideHeight);
			break;
	}

	while ((getchar()) != '\n');

	return successfullyParsedValuesCount;
}

static int loadChosenShapeNumber()
{
	int successfullyParsedValuesCount = scanf("%d", &chosenGeometricShapeNumber);

	while ((getchar()) != '\n');

	return successfullyParsedValuesCount;
}

static void displayChosenShapeAdditionalDataMenu() 
{
	switch (chosenGeometricShapeNumber)
	{
		case CIRCLE:
			printf("Zadejte prumer kruhu v centimetrech: \n");
			break;
		case RECTANGLE:
			printf("Zadejte obe strany obdelnika v centimetrech (oddeleno mezerou): \n");
			break;
		case TRIANGLE:
			printf("Zadejte stranu a vysku strany trojuhelnika v centimetrech (oddeleno mezerou): \n");
			break;
	}
}