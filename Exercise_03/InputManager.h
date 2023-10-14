#ifndef INPUT_MANAGER_H

#define INPUT_MANAGER_H

#define CIRCLE 1
#define RECTANGLE 2
#define TRIANGLE 3

#define GEOMETRIC_SHAPE_NUMBER_NOT_PARSED_ERROR_CODE 1
#define GEOMETRIC_SHAPE_NUMBER_NOT_VALID_ERROR_CODE 2

#define GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_PARSED_ERROR_CODE 3
#define GEOMETRIC_SHAPE_ADDITIONAL_DATA_NOT_VALID_ERROR_CODE 4

extern int chosenGeometricShapeNumber;
extern double inputCircleDiameter;
extern double inputRectangleSideA;
extern double inputRectangleSideB;
extern double inputTriangleSideHeight;
extern double inputTriangleSide;

int loadGeometricShapeData();
static void displayGeometricShapesMenu();
static int loadChosenShapeAdditionalData();
static int loadChosenShapeNumber();
static void displayChosenShapeAdditionalDataMenu();
static int checkChosenGeometricShapeNumberValidity(int successfullyParsedValuesCount);
static int checkChosenGeometricShapeAdditionalDataValidity(int successfullyParsedValuesCount);

#endif
