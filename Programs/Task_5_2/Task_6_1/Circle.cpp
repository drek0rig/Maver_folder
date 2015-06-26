#include "Circle.h"

int Circle::GetCenterX() const
{
	return _centerX;
}

void Circle::SetCenterX(int x)
{
	_centerX = x;
}

int Circle::GetCenterY() const
{
	return _centerY;
}

void Circle::SetCenterY(int y)
{
	_centerY = y;
}

int Circle::GetRadius() const
{
	return _radius;
}

void Circle::SetRadius(int radius)
{
	_radius = radius;
}

void Circle::CircleDecrease()
{
	_radius -= 1;
}

void Circle::CircleIncrease()
{
	_radius += 1;
}

void Circle::CircleShifting (int direction)
{
	if (1 == direction)
	{
		_centerX -= 1;
	}
	else if (2 == direction)
	{
		_centerX += 1;
	}
	else if (3 == direction)
	{
		_centerY += 1;
	}
	else if (4 == direction)
	{
		_centerY -= 1;
	}
}