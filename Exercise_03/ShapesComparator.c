#include "ShapesComparator.h"

int uniqueShapesCount = 0;
int firstShapeNumber = 0;
int secondShapeNumber = 0;
int thirdShapeNumber = 0;

void shiftShapesList(int chosenGeometricShapeNumber)
{

	if (chosenGeometricShapeNumber == thirdShapeNumber || chosenGeometricShapeNumber == secondShapeNumber || chosenGeometricShapeNumber == firstShapeNumber)
	{
		uniqueShapesCount = 1;

		firstShapeNumber = 0;
		secondShapeNumber = 0;
		thirdShapeNumber = chosenGeometricShapeNumber;
	}
	else
	{
		firstShapeNumber = secondShapeNumber;
		secondShapeNumber = thirdShapeNumber;
		thirdShapeNumber = chosenGeometricShapeNumber;

		uniqueShapesCount++;
	}
}

double getPercentualDifferenceLastShapePreviousShape(double lastShapeArea, double previousShapeArea)
{
	double difference = 0;

	difference = (lastShapeArea / previousShapeArea) * 100;

	if (difference < 100) 
	{
		difference = 100 - difference;
		difference = difference * -1;
	}
	else if (difference > 100) 
	{
		difference = difference - 100;
	}
	else 
	{
		difference = 0;
	}

	return difference;
}

double getPercentualDifferenceLastShapeFirstShape(double lastShapeArea, double firstShapeArea)
{
	double difference = 0;

	difference = (lastShapeArea / firstShapeArea) * 100;

	if (difference < 100)
	{
		difference = 100 - difference;
		difference = difference * -1;
	}
	else if (difference > 100)
	{
		difference = difference - 100;
	}
	else
	{
		difference = 0;
	}

	return difference;
}