#include "CircleTools.h"

double circleDiameter = 0;
double circleArea = 0;

void calculateCircleArea(double inputCircleDiameter)
{
	circleDiameter = inputCircleDiameter;
	circleArea = PI * expTwo(inputCircleDiameter / 2);
}