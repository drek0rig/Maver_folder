#include "Rectangle.h"
#include <stdio.h>

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kPrintContentFormatString[] = "\nContent of rectangle:\n"
												 "Bottom left coordinate (X, Y) = (%0.2lf, %0.2lf).\n"
												 "Size(width, height) = (%0.2lf, %0.2lf).\n";

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Rectangle::Rectangle()
{}

Rectangle::~Rectangle()
{}

Point Rectangle::getBottomLeftPoint() const
{
	return _bottomLeftPoint;
}

void Rectangle::setBottomLeftPoint(Point newPoint)
{
	_bottomLeftPoint = newPoint;
}

Size Rectangle::getSize() const
{
	return _size;
}

void Rectangle::setSize(Size newSize)
{
	_size = newSize;
}
 
void Rectangle::makeResize(bool isIncrease)
{
	double offset = isIncrease ? 1.0f : -1.0f;

	_size.width += offset;
	_size.height += offset;
}

void Rectangle::makeMove(DirectionMoveType direction)
{
	switch (direction)
	{
		case kUpDirectionMove:
		{
			_bottomLeftPoint.y++;
			break;
		}
		case kDownDirectionMove:
		{
			_bottomLeftPoint.y--;
			break;
		}
		case kRightDirectionMove:
		{
			_bottomLeftPoint.x++;
			break;
		}
		case kLeftDirectionMove:
		{
			_bottomLeftPoint.x--;
			break;
		}
		default:
			break;
	}
}

void Rectangle::printContent() const
{
	printf(kPrintContentFormatString, _bottomLeftPoint.x, _bottomLeftPoint.y, 
									  _size.width, _size.height);
}
