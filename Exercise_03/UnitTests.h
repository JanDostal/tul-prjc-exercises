#ifndef UNIT_TESTS_H

#define UNIT_TESTS_H

#define TEST_SUCCESS 0
#define TEST_FAILURE 1

int testCircleTools(double referenceCircleDiameter, double referenceCircleArea, int decimalPlacesAccuracy);
int testRectangleTools(double referenceRectangleSideA, double referenceRectangleSideB, double referenceRectangleArea, int decimalPlacesAccuracy);
int testTriangleTools(double referenceTriangleSideHeight, double referenceTriangleSide, double referenceTriangleArea, int decimalPlacesAccuracy);

int testShapesComparatorShiftShapesList(int referenceChosenGeometricShapeNumber, int referenceUniqueShapesCount, 
										int referenceFirstShapeNumber, int referenceSecondShapeNumber, int referenceThirdShapeNumber);

int testShapesComparatorGetPercentualDifferenceLastShapePreviousShape(double referenceLastShapeArea, double referencePreviousShapeArea, 
																	  double referencePercentualDifference, int decimalPlacesAccuracy);

int testShapesComparatorGetPercentualDifferenceLastShapeFirstShape(double referenceLastShapeArea, double referenceFirstShapeArea, double referencePercentualDifference, 
																   int decimalPlacesAccuracy);

int testInputManagerLoadGeometricShapeData();

#endif