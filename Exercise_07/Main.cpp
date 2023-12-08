#include "StringMy.h"

#include <iostream>

int main() 
{
	Style* italic = new Italic();
	Style* bold = new Bold();

	Editor a("hello");
	Editor b("world");

	a.AddStyle(*italic);

	printf("a: %s\n", a.GetFormattedText().c_str());
	printf("b: %s\n", b.GetFormattedText().c_str());

	Editor c = a + Editor(" ") + b;

	c.AddStyle(*bold);

	printf("c: %s\n", c.GetFormattedText().c_str());

	return 0;
}