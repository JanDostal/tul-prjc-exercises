#ifndef PLOTTER_H

#define PLOTTER_H

#include "Color.h"
#include "Pen.h"

#include <vector>

#define USED_COLORS_CAPACITY 3

class Plotter
{
private:
	int usedColorsCount = 0;
	Color* usedColors[USED_COLORS_CAPACITY];
	std::vector<Pen*> pens;

	const bool CheckInsertedPenValidity(const int penWidth, const int penRgbRed, const int penRgbBlue, const int penRgbGreen) const;

public:

	Plotter();
	void Draw(const int penWidth, const int penRgbRed, const int penRgbBlue, const int penRgbGreen);
};

#endif