#include "TriangleTools.h"

double triangleSideHeight = 0;
double triangleSide = 0;
double triangleArea = 0;

void calculateTriangleArea(double inputTriangleSideHeight, double inputTriangleSide) 
{
	triangleSideHeight = inputTriangleSideHeight;
	triangleSide = inputTriangleSide;

	triangleArea = (inputTriangleSide * inputTriangleSideHeight) / 2;
}