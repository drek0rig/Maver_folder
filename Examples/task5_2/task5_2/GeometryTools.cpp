#include "GeometryTools.h"

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(double newX, double newY)
{
	x = newX;
	y = newY;
}

Size::Size()
{
	width = 1.0f;
	height = 1.0f;
}

Size::Size(double newWidth, double newHeight)
{
	width = newWidth;
	height = newHeight;
}
