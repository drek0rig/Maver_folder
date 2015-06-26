#ifndef CIRCLE_H
#define CIRCLE_H
#pragma once

#include "GeometryTools.h"

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Circle
{
public:
	Circle();
	~Circle();

	Point getCenterPoint() const;
	void setCenterPoint(Point newPoint);

	double getRadius() const;
	void setRadius(double newRadius);

    void makeResize(bool isIncrease);
	void makeMove(DirectionMoveType direction);
	void printContent() const;

private:
	Point	_centerPoint;
	double	_radius;
};

#endif