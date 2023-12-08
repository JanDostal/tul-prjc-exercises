#include "Plotter.h"

#include <iostream>

#define TEST_SAMPLES_COUNT 12

int main()
{
	int pensWidths[TEST_SAMPLES_COUNT] = { -2, 0, 5, 8, 10, 10, 5, 5, 7, 8, 9, 10 };
	int pensColors[TEST_SAMPLES_COUNT][3] = { { -1, 3, 4}, { 2, -1, 4}, { 2, 3, -1 },
		{ 300, 3, 4}, { 2, 300, 4}, { 2, 3, 300}, { 2, 3, 5}, { 2, 3, 5}, { 2, 3, 7}, { 2, 3, 7}, { 2, 3, 8}, { 2, 3, 9} };

	Plotter plotr;

	for (register int i = 0; i < TEST_SAMPLES_COUNT; i++) 
	{
		try 
		{
			plotr.Draw(pensWidths[i], pensColors[i][0], pensColors[i][1], pensColors[i][2]);
		}
		catch (std::exception& ex) 
		{
			std::cout << ex.what() << std::endl;
		}
	}

	return 0;
}