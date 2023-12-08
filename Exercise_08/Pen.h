#ifndef PEN_H

#define PEN_H

#include "Color.h"

#include <string>

class Pen
{
private:
	Color* color;
	int width;

public:
	Pen(const int _width, Color* const _color);

	Color const* const GetColor() const;
	const int GetWidth() const;

	const std::string ToString() const;
};

#endif
