#include "Triangle.h"

int Triangle::GetFirstPointX() const
{
	return _firstPointX;
}

void Triangle::SetFirstPointX(int x)
{
	_firstPointX = x;
}

int Triangle::GetFirstPointY() const
{
	return _firstPointY;
}

void Triangle::SetFirstPointY(int y)
{
	_firstPointY = y;
}

int Triangle::GetSecondPointX() const
{
	return _secondPointX;
}

void Triangle::SetSecondPointX(int x)
{
	_secondPointX = x;
}

int Triangle::GetSecondPointY() const
{
	return _secondPointY;
}

void Triangle::SetSecondPointY(int y)
{
	_secondPointY = y;
}

int Triangle::GetThirdPointX() const
{
	return _thirdPointX;
}

void Triangle::SetThirdPointX(int x)
{
	_thirdPointX = x;
}

int Triangle::GetThirdPointY() const
{
	return _thirdPointY;
}

void Triangle::SetThirdPointY(int y)
{
	_thirdPointY = y;
}

void Triangle::TriangleDecrease()
{
	_secondPointX -= 1;
	_secondPointY -= 1;
	_thirdPointX -= 1;
	_thirdPointY -= 1;
}

void Triangle::TriangleIncrease()
{
	_secondPointX += 1;
	_secondPointY += 1;
	_thirdPointX += 1;
	_thirdPointY += 1;
}

void Triangle::TriangleShifting (int direction)
{
	if (1 == direction)
	{
		_firstPointX -= 1;
		_secondPointX -= 1;		
		_thirdPointX -= 1;
	}
	else if (2 == direction)
	{
		_firstPointX += 1;
		_secondPointX += 1;		
		_thirdPointX += 1;
	}
	else if (3 == direction)
	{
		_firstPointY += 1;
		_secondPointY += 1;		
		_thirdPointY += 1;
	}
	else if (4 == direction)
	{
		_firstPointY -= 1;
		_secondPointY -= 1;		
		_thirdPointY -= 1;
	}
}