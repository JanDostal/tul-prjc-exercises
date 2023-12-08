#include "Color.h"

Color::Color(const int _red, const int _green, const int _blue) : red(_red), green(_green), blue(_blue) {}

const int Color::GetRed() const
{
	return red;
}

const int Color::GetGreen() const
{
	return green;
}

const int Color::GetBlue() const
{
	return blue;
}