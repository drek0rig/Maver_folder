#ifndef GEOMETRY_TOOLS_H
#define GEOMETRY_TOOLS_H
#pragma once

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

typedef enum
{
	kUpDirectionMove		= 1,
	kDownDirectionMove		= 2,
	kLeftDirectionMove		= 3,
	kRightDirectionMove		= 4
} DirectionMoveType;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Point
{
public:
	Point();
	Point(double newX, double newY);

	double x;
	double y;
};

class Size
{
public:
	Size();
	Size(double newWidth, double newHeight);

	double width;
	double height;
};

/*
	OR
typedef struct
{
	double x;
	double y;
} Point;
*/

#endif