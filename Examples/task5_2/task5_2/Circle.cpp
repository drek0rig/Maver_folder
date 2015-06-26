#include "Circle.h"
#include <stdio.h>

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kPrintContentFormatString[] = "\nContent of circle:\n"
												 "Center coordinate (X, Y) = (%0.2lf, %0.2lf).\n"
												 "Radius = %0.2lf.\n";

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Circle::Circle()
{}

Circle::~Circle()
{}

Point Circle::getCenterPoint() const
{
	return _centerPoint;
}

void Circle::setCenterPoint(Point newPoint)
{
	_centerPoint = newPoint;
}

double Circle::getRadius() const
{
	return _radius;
}

void Circle::setRadius(double newRadius)
{
	_radius = newRadius;
}

void Circle::makeResize(bool isIncrease)
{
	_radius += isIncrease ? 1.0f : -1.0f;
}

void Circle::makeMove(DirectionMoveType direction)
{
	switch (direction)
	{
		case kUpDirectionMove:
		{
			_centerPoint.y++;
			break;
		}
		case kDownDirectionMove:
		{
			_centerPoint.y--;
			break;
		}
		case kRightDirectionMove:
		{
			_centerPoint.x++;
			break;
		}
		case kLeftDirectionMove:
		{
			_centerPoint.x--;
			break;
		}
		default:
			break;
	}
}

void Circle::printContent() const
{
	printf(kPrintContentFormatString, _centerPoint.x, _centerPoint.y, _radius);
}

