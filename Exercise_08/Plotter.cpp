#include "Plotter.h"

#include <iostream>

Plotter::Plotter() 
{
	for (register int i = 0; i < USED_COLORS_CAPACITY; i++)
	{
		usedColors[i] = NULL;
	}
}

const bool Plotter::CheckInsertedPenValidity(const int penWidth, const int penRgbRed, const int penRgbBlue, 
											const int penRgbGreen) const
{
	if (penWidth < 0)
	{
		throw std::exception("Pen width must not be less than zero");
	}

	if (penWidth == 0)
	{
		throw std::exception("Pen width must not be equal to zero");
	}

	if ((penRgbRed < 0 || penRgbRed > 255) || (penRgbBlue < 0 || penRgbBlue > 255) || (penRgbGreen < 0 || penRgbGreen > 255))
	{
		throw std::exception("Pen color does not exist");
	}

	bool isPenColorAlreadyExisting = false;
	register Color* foundColor;

	for (register int i = 0; i < USED_COLORS_CAPACITY && isPenColorAlreadyExisting == false; i++)
	{
		foundColor = usedColors[i];

		if (foundColor != NULL && foundColor->GetBlue() == penRgbBlue &&
			foundColor->GetGreen() == penRgbGreen && foundColor->GetRed() == penRgbRed)
		{
			isPenColorAlreadyExisting = true;
		}
	}

	if (isPenColorAlreadyExisting == false && usedColorsCount == USED_COLORS_CAPACITY)
	{
		throw std::exception("Plotter must not have more than three colors");
	}

	bool isPenAlreadyExisting = false;
	const size_t usedPensCount = pens.size();
	register Pen* foundPen;
	register const Color const* foundPenColor;

	for (register int i = 0; i < usedPensCount && isPenAlreadyExisting == false; i++)
	{
		foundPen = pens.at(i);
		foundPenColor = foundPen->GetColor();

		if (foundPenColor->GetBlue() == penRgbBlue &&
			foundPenColor->GetGreen() == penRgbGreen &&
			foundPenColor->GetRed() == penRgbRed &&
			foundPen->GetWidth() == penWidth)
		{
			isPenAlreadyExisting = true;
		}
	}

	return isPenAlreadyExisting;
}

void Plotter::Draw(const int penWidth, const int penRgbRed, const int penRgbBlue, const int penRgbGreen)
{
	const bool isPenAlreadyExisting = CheckInsertedPenValidity(penWidth, penRgbRed, penRgbBlue, penRgbGreen);

	register Pen* selectedPen = NULL;

	if (isPenAlreadyExisting == false) 
	{
		bool isPenColorAlreadyExisting = false;
		register Color* foundColor = NULL;

		for (register int i = 0; i < USED_COLORS_CAPACITY && isPenColorAlreadyExisting == false; i++)
		{
			foundColor = usedColors[i];

			if (foundColor != NULL && foundColor->GetBlue() == penRgbBlue && foundColor->GetRed() == penRgbRed &&
				foundColor->GetGreen() == penRgbGreen)
			{
				isPenColorAlreadyExisting = true;
			}
		}

		if (isPenColorAlreadyExisting == true) 
		{
			selectedPen = new Pen(penWidth, foundColor);
		}
		else 
		{
			Color* newColor = new Color(penRgbRed, penRgbGreen, penRgbBlue);

			register int index = 0;
			while (usedColors[index] != NULL)
			{
				index++;
			}

			usedColors[index] = newColor;
			usedColorsCount++;
			
			selectedPen = new Pen(penWidth, newColor);
		}

		pens.push_back(selectedPen);
	}
	else 
	{
		const size_t usedPensCount = pens.size();
		bool wasPenFound = false;
		register const Color const* selectedPenColor;

		for (register int i = 0; i < usedPensCount && wasPenFound == false; i++)
		{
			selectedPen = pens.at(i);
			selectedPenColor = selectedPen->GetColor();

			if (selectedPenColor->GetBlue() == penRgbBlue &&
				selectedPenColor->GetGreen() == penRgbGreen &&
				selectedPenColor->GetRed() == penRgbRed &&
				selectedPen->GetWidth() == penWidth)
			{
				wasPenFound = true;
			}
		}
	}

	std::cout << selectedPen->ToString() << std::endl;
}