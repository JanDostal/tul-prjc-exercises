#ifndef IO_MANAGER_H

#define IO_MANAGER_H

#define CIRCLE 1
#define RECTANGLE 2
#define TRIANGULAR 3

extern int chosenGeometricShapeNumber;
extern float circleDiameter;
extern float rectangleSideA;
extern float rectangleSideB;
extern float triangleSideHeight;
extern float triangleSide;

int loadGeometricShape();
static void displayGeometricShapesMenu();
static int loadAdditionalChoice(int chosenShape);
static void displayAdditionalMenu(int chosenShape);

#endif
