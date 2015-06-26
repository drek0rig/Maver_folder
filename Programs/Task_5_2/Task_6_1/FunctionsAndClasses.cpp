#include "FunctionsAndClasses.h"

// Rectangle class methods

int Rectangle::GetLeftDownAngleX()
{
	return _lefDownAnglX;
}

void Rectangle::SetLeftDownAngleX (int coordinateX)
{
	_lefDownAnglX = coordinateX;
}

int Rectangle::GetLeftDownAngleY()
{
	return _lefDownAnglY;
}

void Rectangle::SetLeftDownAngleY (int coordinateY)
{
	_lefDownAnglY = coordinateY;
}

int Rectangle::GetWidth()
{
	return _width;
}

void Rectangle::SetWidth (int width)
{
	_width = width;
}

int Rectangle::GetHeight()
{
	return _height;
}

void Rectangle::SetHeight (int height)
{
	_height = height;
}

void Rectangle::WidthDecrease()
{
	_width -= 1;
}

void Rectangle::HeightDecrease()
{
	_height -= 1;
}

void Rectangle::WidthIncrease()
{
	_width += 1;
}

void Rectangle::HeightIncrease()
{
	_height += 1;
}

void Rectangle::RectangleShifting (int direction)
{
	if (1 == direction)
	{
		_lefDownAnglX -= 1;
	}
	else if (2 == direction)
	{
		_lefDownAnglX += 1;
	}
	else if (3 == direction)
	{
		_lefDownAnglY += 1;
	}
	else if (4 == direction)
	{
		_lefDownAnglY -= 1;
	}
}