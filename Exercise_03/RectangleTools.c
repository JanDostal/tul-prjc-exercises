#include "RectangleTools.h"

double rectangleSideA = 0;
double rectangleSideB = 0;
double rectangleArea = 0;

void calculateRectangleArea(double inputRectangleSideA, double inputRectangleSideB)
{
	rectangleSideA = inputRectangleSideA;
	rectangleSideB = inputRectangleSideB;

	rectangleArea = inputRectangleSideA * inputRectangleSideB;
}