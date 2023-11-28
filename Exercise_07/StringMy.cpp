#include "StringMy.h"

const std::string Bold::GetFormat(const std::string text) 
{
	std::string formattedText;

	formattedText = "<b>" + text + "</b>";

	return formattedText;
}

const std::string Italic::GetFormat(const std::string text) 
{
	std::string formattedText;

	formattedText = "<i>" + text + "</i>";

	return formattedText;
}

Editor::Editor(const std::string _text) : text(_text) {}

const std::string Editor::GetFormattedText() const
{
	std::string formattedText = text;

	for (Style* style : styles)
	{
		formattedText = style->GetFormat(formattedText);
	}

	return formattedText;
}

void Editor::AddStyle(Style& const style)
{
	styles.push_back(&style);
}

Editor Editor::operator+(Editor const& const editor)
{
	Editor newEditor(this->GetFormattedText() + editor.GetFormattedText());

	return newEditor;
}