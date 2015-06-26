#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
	int GetCenterX() const;
	void SetCenterX(int x);
	int GetCenterY() const;
	void SetCenterY(int y);

	int GetRadius() const;
	void SetRadius(int radius);

	void CircleDecrease();
	void CircleIncrease();

	void CircleShifting(int direction);
private:
	int _centerX;
	int _centerY;
	int _radius;
};

#endif