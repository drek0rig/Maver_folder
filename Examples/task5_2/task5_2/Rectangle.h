#ifndef RECTANGLE_H
#define RECTANGLE_H
#pragma once

#include "GeometryTools.h"

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Rectangle
{
public:
	Rectangle();
	~Rectangle();

	Point getBottomLeftPoint() const;
	void setBottomLeftPoint(Point newPoint);

	Size getSize() const;
	void setSize(Size newSize);

    void makeResize(bool isIncrease);
	void makeMove(DirectionMoveType direction);
	void printContent() const;

private:
	Point	_bottomLeftPoint;
	Size	_size;
};

#endif