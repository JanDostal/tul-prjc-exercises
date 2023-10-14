#define _CRT_SECURE_NO_WARNINGS

#include "UnitTests.h"

#include "CircleTools.h"
#include "RectangleTools.h"
#include "TriangleTools.h"
#include "ShapesComparator.h"
#include "InputManager.h"

#include "math.h"
#include "stdio.h"

int testCircleTools(double referenceCircleDiameter, double referenceCircleArea, int decimalPlacesAccuracy)
{
	int successCode = 0;
	char outputText[150] = { 0 };

	calculateCircleArea(referenceCircleDiameter);

	referenceCircleArea = floor(referenceCircleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);
	double realCircleArea = floor(circleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);

	if (referenceCircleArea == realCircleArea) 
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni circleArea =", "%.", decimalPlacesAccuracy, "f", 
			"a realna circleArea =", "%.", decimalPlacesAccuracy, "f", "se shoduji");
		successCode = TEST_SUCCESS;
	}
	else 
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni circleArea =", "%.", decimalPlacesAccuracy, "f", 
			"a realna circleArea =", "%.", decimalPlacesAccuracy, "f", "se neshoduji");
		successCode = TEST_FAILURE;
	}

	printf(outputText, referenceCircleArea, realCircleArea);

	return successCode;
}

int testRectangleTools(double referenceRectangleSideA, double referenceRectangleSideB, double referenceRectangleArea, int decimalPlacesAccuracy)
{
	int successCode = 0;
	char outputText[150] = { 0 };

	calculateRectangleArea(referenceRectangleSideA, referenceRectangleSideB);

	referenceRectangleArea = floor(referenceRectangleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);
	double realRectangleArea = floor(rectangleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);

	if (referenceRectangleArea == realRectangleArea)
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni rectangleArea =", "%.", decimalPlacesAccuracy, "f",
			"a realna rectangleArea =", "%.", decimalPlacesAccuracy, "f", "se shoduji");
		successCode = TEST_SUCCESS;
	}
	else
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni rectangleArea =", "%.", decimalPlacesAccuracy, "f",
			"a realna rectangleArea =", "%.", decimalPlacesAccuracy, "f", "se neshoduji");
		successCode = TEST_FAILURE;
	}

	printf(outputText, referenceRectangleArea, realRectangleArea);

	return successCode;
}

int testTriangleTools(double referenceTriangleSideHeight, double referenceTriangleSide, double referenceTriangleArea, int decimalPlacesAccuracy)
{
	int successCode = 0;
	char outputText[150] = { 0 };

	calculateTriangleArea(referenceTriangleSideHeight, referenceTriangleSide);

	referenceTriangleArea = floor(referenceTriangleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);
	double realTriangleArea = floor(triangleArea * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);

	if (referenceTriangleArea == realTriangleArea)
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni triangleArea =", "%.", decimalPlacesAccuracy, "f",
			"a realna triangleArea =", "%.", decimalPlacesAccuracy, "f", "se shoduji");
		successCode = TEST_SUCCESS;
	}
	else
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni triangleArea =", "%.", decimalPlacesAccuracy, "f",
			"a realna triangleArea =", "%.", decimalPlacesAccuracy, "f", "se neshoduji");
		successCode = TEST_FAILURE;
	}

	printf(outputText, referenceTriangleArea, realTriangleArea);

	return successCode;
}

int testShapesComparatorShiftShapesList(int referenceChosenGeometricShapeNumber, int referenceUniqueShapesCount,
	int referenceFirstShapeNumber, int referenceSecondShapeNumber, int referenceThirdShapeNumber)
{
	int successCode = 0;

	shiftShapesList(referenceChosenGeometricShapeNumber);

	printf("%-40s pocet unikatnich tvaru = %d, prvni tvar = %d, druhy tvar = %d, treti tvar = %d\n", "referencni hodnoty shiftShapesList:",
		referenceUniqueShapesCount, referenceFirstShapeNumber, referenceSecondShapeNumber, referenceThirdShapeNumber);

	printf("%-40s pocet unikatnich tvaru = %d, prvni tvar = %d, druhy tvar = %d, treti tvar = %d\n", "realne hodnoty shiftShapesList:",
		uniqueShapesCount, firstShapeNumber, secondShapeNumber, thirdShapeNumber);

	if (referenceUniqueShapesCount != uniqueShapesCount || referenceFirstShapeNumber != firstShapeNumber || 
		referenceSecondShapeNumber != secondShapeNumber || referenceThirdShapeNumber != thirdShapeNumber) 
	{
		printf("neshoduji se\n");
		successCode = TEST_FAILURE;
	}
	else 
	{
		printf("shoduji se\n");
		successCode = TEST_SUCCESS;
	}

	return successCode;
}

int testShapesComparatorGetPercentualDifferenceLastShapePreviousShape(double referenceLastShapeArea, double referencePreviousShapeArea, 
																	  double referencePercentualDifference, int decimalPlacesAccuracy)
{
	int successCode = 0;
	char outputText[150] = { 0 };

	referencePercentualDifference = floor(referencePercentualDifference * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);
	double realPercentualDifference = getPercentualDifferenceLastShapePreviousShape(referenceLastShapeArea, referencePreviousShapeArea);

	if (realPercentualDifference < 0) 
	{
		realPercentualDifference = realPercentualDifference * -1;
	}

	realPercentualDifference = floor(realPercentualDifference * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);

	if (referencePercentualDifference == realPercentualDifference)
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni percentualDifferenceLastShapePreviousShape =", "%.", decimalPlacesAccuracy, "f",
			"a realna percentualDifferenceLastShapePreviousShape =", "%.", decimalPlacesAccuracy, "f", "se shoduji");
		successCode = TEST_SUCCESS;
	}
	else
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni percentualDifferenceLastShapePreviousShape =", "%.", decimalPlacesAccuracy, "f",
			"a realna percentualDifferenceLastShapePreviousShape =", "%.", decimalPlacesAccuracy, "f", "se neshoduji");
		successCode = TEST_FAILURE;
	}

	printf(outputText, referencePercentualDifference, realPercentualDifference);

	return successCode;
}
int testShapesComparatorGetPercentualDifferenceLastShapeFirstShape(double referenceLastShapeArea, double referenceFirstShapeArea, double referencePercentualDifference, 
																   int decimalPlacesAccuracy)
{
	int successCode = 0;
	char outputText[150] = { 0 };

	referencePercentualDifference = floor(referencePercentualDifference * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);
	double realPercentualDifference = getPercentualDifferenceLastShapeFirstShape(referenceLastShapeArea, referenceFirstShapeArea);

	if (realPercentualDifference < 0)
	{
		realPercentualDifference = realPercentualDifference * -1;
	}

	realPercentualDifference = floor(realPercentualDifference * (10 ^ decimalPlacesAccuracy)) / (10 ^ decimalPlacesAccuracy);

	if (referencePercentualDifference == realPercentualDifference)
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni percentualDifferenceLastShapeFirstShape =", "%.", decimalPlacesAccuracy, "f",
			"a realna percentualDifferenceLastShapeFirstShape =", "%.", decimalPlacesAccuracy, "f", "se shoduji");
		successCode = TEST_SUCCESS;
	}
	else
	{
		sprintf(outputText, "%s %s%d%s %s %s%d%s %s\n", "referencni percentualDifferenceLastShapeFirstShape =", "%.", decimalPlacesAccuracy, "f",
			"a realna percentualDifferenceLastShapeFirstShape =", "%.", decimalPlacesAccuracy, "f", "se neshoduji");
		successCode = TEST_FAILURE;
	}

	printf(outputText, referencePercentualDifference, realPercentualDifference);

	return successCode;
}

int testInputManagerLoadGeometricShapeData()
{
	int successCode = 0;

	successCode = loadGeometricShapeData();
	
	switch (successCode)
	{
		case GEOMETRIC_SHAPE_NUMBER_NOT_PARSED_ERROR_CODE:

			printf("\nNepodarilo se nacist cislo volby vybraneho geometrickeho tvaru, zadavejte cele cislo\n");
			break;

		case GEOMETRIC_SHAPE_NUMBER_NOT_VALID_ERROR_CODE:

			printf("\nNactene cislo volby vybraneho geometrickeho tvaru je neplatne\n");
			break;

		case GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_PARSED_ERROR_CODE:

			switch (chosenGeometricShapeNumber)
			{
				case CIRCLE:

					printf("\nNepodarilo se nacist prumer kruhu\n");
					break;

				case RECTANGLE:
	
					printf("\nNepodarily se nacist strany A a B u obdelniku\n");
					break;

				case TRIANGLE:

					printf("\nNepodarily se nacist strana trojuhelnika a vyska strany trojuhelnika\n");
					break;
			}

			break;

		case GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_VALID_ERROR_CODE:

			switch (chosenGeometricShapeNumber)
			{
				case CIRCLE:

					printf("\nNacteny prumer kruhu musi byt vetsi nez nula\n");
					break;

				case RECTANGLE:

					printf("\nNactene strany obdelnika A a B musi byt vetsi nez nula\n");
					break;

				case TRIANGLE:

					printf("\nNactene strana trojuhelnika a vyska strany trojuhelnika musi byt vetsi nez nula\n");
					break;
			}

			break;
	}

	if (successCode != 0) 
	{
		successCode = TEST_FAILURE;
	}
	else 
	{
		successCode = TEST_SUCCESS;
	}

	return successCode;
}