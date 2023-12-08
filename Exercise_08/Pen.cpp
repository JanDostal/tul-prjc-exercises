#define _CRT_SECURE_NO_WARNINGS

#include "Pen.h"

Pen::Pen(const int _width, Color* const _color) : width(_width), color(_color) {}

Color const* const Pen::GetColor() const 
{
	return color;
}

const int Pen::GetWidth() const
{
	return width;
}

const std::string Pen::ToString() const
{
	char instanceRepresentationBuffer[100];
	
	sprintf(instanceRepresentationBuffer, "R:%dG:%dB:%dW:%d", color->GetRed(), color->GetGreen(), color->GetBlue(), width);

	std::string instanceRepresentation = instanceRepresentationBuffer;

	return instanceRepresentation;
}