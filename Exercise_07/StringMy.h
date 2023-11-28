#ifndef STRING_MY_H

#define STRING_MY_H

#include <string>
#include <vector>

class Style 
{
public:
	virtual const std::string GetFormat(const std::string text) = 0;
};

class Bold : public Style
{
public:
	const std::string GetFormat(const std::string text);
};

class Italic : public Style
{
public:
	const std::string GetFormat(const std::string text);
};

class Editor
{
private:
	std::string text;
	std::vector<Style *> styles;

public:

	Editor(const std::string _text);

	const std::string GetFormattedText() const;
	void AddStyle(Style& const style);
	Editor operator+(Editor const& const editor);
};

#endif
