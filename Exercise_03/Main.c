#define _CRT_SECURE_NO_WARNINGS

#include "InputManager.h"
#include "CircleTools.h"
#include "RectangleTools.h"
#include "TriangleTools.h"
#include "ShapesComparator.h"

#include "stdio.h"
#include "stdbool.h"

static void printErrorMessage(int errorCode);
static void printChosenShapeArea();
static void printDifferenceComparisonBetweenShapes();
static void printDifferenceComparisonBetweenPreviousShape(char* lastShapeType);
static void printDifferenceComparisonBetweenFirstShape(char* lastShapeType);

int main()
{
	int answer = -1;
	register int errorCode = 0;
	register bool isProgramRunning = true;

	while (isProgramRunning == true) 
	{
		errorCode = loadGeometricShapeData();

		if (errorCode != 0)
		{
			printErrorMessage(errorCode);
		}
		else 
		{
			printChosenShapeArea();

			printDifferenceComparisonBetweenShapes();
		}

		printf("\nChcete pokracovat v zadavani dalsich geometrickych tvaru? Pro ukonceni zadejte 0: \n");

		scanf("%d", &answer);

		while ((getchar()) != '\n');

		if (answer == 0)
		{
			isProgramRunning = false;
		}
	}

	return 0;
}

static void printDifferenceComparisonBetweenPreviousShape(char* lastShapeType) 
{
	char comparisonTextOutput[100] = { 0 };
	char* lastShapePreviousShapeDifference = "";

	double lastShapeArea = 0;
	double previousShapeArea = 0;

	switch (thirdShapeNumber) 
	{
		case CIRCLE:
			lastShapeArea = circleArea;
			break;
		case RECTANGLE:
			lastShapeArea = rectangleArea;
			break;
		case TRIANGLE:
			lastShapeArea = triangleArea;
			break;
	}

	switch (secondShapeNumber) 
	{
		case CIRCLE:
			previousShapeArea = circleArea;
			break;
		case RECTANGLE:
			previousShapeArea = rectangleArea;
			break;
		case TRIANGLE:
			previousShapeArea = triangleArea;
			break;
	}


	double percentualDifferenceLastShapePreviousShape = getPercentualDifferenceLastShapePreviousShape(lastShapeArea, previousShapeArea);

	if (percentualDifferenceLastShapePreviousShape < 0)
	{
		lastShapePreviousShapeDifference = "ma obsah mensi o";
		sprintf(comparisonTextOutput, "%s %.2f %% %s", lastShapePreviousShapeDifference, percentualDifferenceLastShapePreviousShape * -1, "nez");

	}
	else if (percentualDifferenceLastShapePreviousShape > 0)
	{
		lastShapePreviousShapeDifference = "ma obsah vetsi o";
		sprintf(comparisonTextOutput, "%s %.2f %% %s", lastShapePreviousShapeDifference, percentualDifferenceLastShapePreviousShape, "nez");
	}
	else
	{
		lastShapePreviousShapeDifference = "ma obsah stejny jako";
		sprintf(comparisonTextOutput, "%s", lastShapePreviousShapeDifference);
	}

	switch (secondShapeNumber)
	{
		case CIRCLE:

			printf("Posledni zadany %s %s %s zadany kruh\n", lastShapeType, comparisonTextOutput, uniqueShapesCount == 2 ? "prvni" : "druhy");
			printf("Parametry kruhu: prumer kruhu = %.2f cm, obsah kruhu = %.2f cm2\n\n", circleDiameter, circleArea);
			break;

		case RECTANGLE:

			printf("Posledni zadany %s %s %s zadany obdelnik\n", lastShapeType, comparisonTextOutput, uniqueShapesCount == 2 ? "prvni" : "druhy");
			printf("Parametry obdelniku: strana A = %.2f cm, strana B = %.2f cm, obsah obdelniku = %.2f cm2\n\n", rectangleSideA, rectangleSideB, rectangleArea);
			break;

		case TRIANGLE:

			printf("Posledni zadany %s %s %s zadany trojuhelnik\n", lastShapeType, comparisonTextOutput, uniqueShapesCount == 2 ? "prvni" : "druhy");
			printf("Parametry trojuhelniku: vyska strany = %.2f cm, strana = %.2f cm, obsah trojuhelniku = %.2f cm2\n\n", triangleSideHeight, triangleSide, triangleArea);
			break;
	}
}

static void printDifferenceComparisonBetweenFirstShape(char* lastShapeType) 
{
	char comparisonTextOutput[100] = { 0 };
	char* lastShapeFirstShapeDifference = "";

	double lastShapeArea = 0;
	double firstShapeArea = 0;

	switch (thirdShapeNumber)
	{
		case CIRCLE:
			lastShapeArea = circleArea;
			break;
		case RECTANGLE:
			lastShapeArea = rectangleArea;
			break;
		case TRIANGLE:
			lastShapeArea = triangleArea;
			break;
	}

	switch (firstShapeNumber)
	{
		case CIRCLE:
			firstShapeArea = circleArea;
			break;
		case RECTANGLE:
			firstShapeArea = rectangleArea;
			break;
		case TRIANGLE:
			firstShapeArea = triangleArea;
			break;
	}

	double percentualDifferenceLastShapeFirstShape = getPercentualDifferenceLastShapeFirstShape(lastShapeArea, firstShapeArea);

	if (percentualDifferenceLastShapeFirstShape < 0)
	{
		lastShapeFirstShapeDifference = "ma obsah mensi o";
		sprintf(comparisonTextOutput, "%s %.2f %% %s", lastShapeFirstShapeDifference, percentualDifferenceLastShapeFirstShape * -1, "nez");

	}
	else if (percentualDifferenceLastShapeFirstShape > 0)
	{
		lastShapeFirstShapeDifference = "ma obsah vetsi o";
		sprintf(comparisonTextOutput, "%s %.2f %% %s", lastShapeFirstShapeDifference, percentualDifferenceLastShapeFirstShape, "nez");
	}
	else
	{
		lastShapeFirstShapeDifference = "ma obsah stejny jako";
		sprintf(comparisonTextOutput, "%s", lastShapeFirstShapeDifference);
	}

	switch (firstShapeNumber)
	{
		case CIRCLE:

			printf("Posledni zadany %s %s prvni zadany kruh\n", lastShapeType, comparisonTextOutput);
			printf("Parametry kruhu: prumer kruhu = %.2f cm, obsah kruhu = %.2f cm2\n\n", circleDiameter, circleArea);
			break;

		case RECTANGLE:

			printf("Posledni zadany %s %s prvni zadany obdelnik\n", lastShapeType, comparisonTextOutput);
			printf("Parametry obdelniku: strana A = %.2f cm, strana B = %.2f cm, obsah obdelniku = %.2f cm2\n\n", rectangleSideA, rectangleSideB, rectangleArea);
			break;

		case TRIANGLE:

			printf("Posledni zadany %s %s prvni zadany trojuhelnik\n", lastShapeType, comparisonTextOutput);
			printf("Parametry trojuhelniku: vyska strany = %.2f cm, strana = %.2f cm, obsah trojuhelniku = %.2f cm2\n\n", triangleSideHeight, triangleSide, triangleArea);
			break;
	}
}

static void printDifferenceComparisonBetweenShapes() 
{
	char* lastShapeType = "";

	shiftShapesList(chosenGeometricShapeNumber);

	switch (thirdShapeNumber)
	{
		case CIRCLE:

			lastShapeType = "kruh";
			break;

		case RECTANGLE:

			lastShapeType = "obdelnik";
			break;

		case TRIANGLE:

			lastShapeType = "trojuhelnik";
			break;
	}

	switch (uniqueShapesCount)
	{
		case 2:

			printDifferenceComparisonBetweenPreviousShape(lastShapeType);
			break;

		case 3:

			printDifferenceComparisonBetweenPreviousShape(lastShapeType);
			printDifferenceComparisonBetweenFirstShape(lastShapeType);
			break;
	}


}

static void printChosenShapeArea() 
{
	switch (chosenGeometricShapeNumber)
	{
		case CIRCLE:

			calculateCircleArea(inputCircleDiameter);

			printf("\nObsah kruhu je %.2f cm2\n", circleArea);
			printf("Parametry kruhu: prumer kruhu = %.2f cm\n\n", circleDiameter);
			break;

		case RECTANGLE:

			calculateRectangleArea(inputRectangleSideA, inputRectangleSideB);

			printf("\nObsah obdelniku je %.2f cm2\n", rectangleArea);
			printf("Parametry obdelniku: strana A = %.2f cm, strana B = %.2f cm\n\n", rectangleSideA, rectangleSideB);
			break;

		case TRIANGLE:

			calculateTriangleArea(inputTriangleSideHeight, inputTriangleSide);

			printf("\nObsah trojuhelniku je %.2f cm2\n", triangleArea);
			printf("Parametry trojuhelniku: vyska strany = %.2f cm, strana = %.2f cm\n\n", triangleSideHeight, triangleSide);
			break;
	}
}

static void printErrorMessage(int errorCode) 
{
	switch (errorCode)
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
}