#ifndef COLOR_H

#define COLOR_H

class Color
{
private:
	int red;
	int green;
	int blue;

public:

	Color(const int _red, const int _green, const int _blue);

	const int GetRed() const;
	const int GetGreen() const;
	const int GetBlue() const;
};

#endif
