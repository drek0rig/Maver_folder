#ifndef TRIANGLE_H
#define TRIANGLE_H
#pragma once

#include "GeometryTools.h"

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Triangle
{
public:
	Triangle(void);
	~Triangle(void);

	Point getBottomLeftPoint() const;
	void setBottomLeftPoint(Point newPoint);

	Point getBottomRightPoint() const;
	void setBottomRightPoint(Point newPoint);

	Point getTopPoint() const;
	void setTopPoint(Point newPoint);

    void makeResize(bool isIncrease);
	void makeMove(DirectionMoveType direction);
	void printContent() const;

private:
	Point	_bottomLeftPoint;
	Point	_bottomRightPoint;
	Point	_topPoint;
};

#endif