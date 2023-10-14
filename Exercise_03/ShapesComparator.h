#ifndef SHAPES_COMPARATOR_H

#define SHAPES_COMPARATOR_H

extern int uniqueShapesCount;
extern int firstShapeNumber;
extern int secondShapeNumber;	
extern int thirdShapeNumber;

void shiftShapesList(int chosenGeometricShapeNumber);
double getPercentualDifferenceLastShapePreviousShape(double lastShapeArea, double previousShapeArea);
double getPercentualDifferenceLastShapeFirstShape(double lastShapeArea, double firstShapeArea);

#endif
