#include "Triangle.h"
#include <stdio.h>

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kPrintContentFormatString[] = "\nContent of triangle:\n"
												 "Bottom left coordinate (X, Y) = (%0.2lf, %0.2lf).\n"
												 "Top coordinate (X, Y) = (%0.2lf, %0.2lf).\n"
												 "Bottom right coordinate (X, Y) = (%0.2lf, %0.2lf).\n";

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Triangle::Triangle(void)
{}

Triangle::~Triangle(void)
{}

Point Triangle::getBottomLeftPoint() const
{
	return _bottomLeftPoint;
}

void Triangle::setBottomLeftPoint(Point newPoint)
{
	_bottomLeftPoint = newPoint;
}

Point Triangle::getBottomRightPoint() const
{
	return _bottomRightPoint;
}
	
void Triangle::setBottomRightPoint(Point newPoint)
{
	_bottomRightPoint = newPoint;
}

Point Triangle::getTopPoint() const
{
	return _topPoint;
}

void Triangle::setTopPoint(Point newPoint)
{
	_topPoint = newPoint;
}

void Triangle::makeResize(bool isIncrease)
{
	double offset = isIncrease ? 1.0f : -1.0f;

	_bottomRightPoint.x += offset;
	_bottomRightPoint.y += offset;

	_topPoint.x += offset;
	_topPoint.y += offset;
}

void Triangle::makeMove(DirectionMoveType direction)
{
	switch (direction)
	{
		case kUpDirectionMove:
		{
			_bottomLeftPoint.y++;
			_bottomRightPoint.y++;
			_topPoint.y++;
			break;
		}
		case kDownDirectionMove:
		{
			_bottomLeftPoint.y--;
			_bottomRightPoint.y--;
			_topPoint.y--;
			break;
		}
		case kRightDirectionMove:
		{
			_bottomLeftPoint.x++;
			_bottomRightPoint.x++;
			_topPoint.x++;
			break;
		}
		case kLeftDirectionMove:
		{
			_bottomLeftPoint.x--;
			_bottomRightPoint.x--;
			_topPoint.x--;
			break;
		}
		default:
			break;
	}
}

void Triangle::printContent() const
{
	printf(kPrintContentFormatString, _bottomLeftPoint.x, _bottomLeftPoint.y,
									  _topPoint.x, _topPoint.y,
									  _bottomRightPoint.x, _bottomRightPoint.y);
}

