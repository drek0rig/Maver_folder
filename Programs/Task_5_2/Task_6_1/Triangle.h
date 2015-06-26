#ifndef TRIANGLE_H
#define TRIANGLE_H

// ���� �� ����, �� firstPoint - ����� ���, secondPoint - ����� �����, thirdPoint - ������

class Triangle
{
public:
	int GetFirstPointX() const;
	void SetFirstPointX(int x);
	int GetFirstPointY() const;
	void SetFirstPointY(int y);

	int GetSecondPointX() const;
	void SetSecondPointX(int x);
	int GetSecondPointY() const;
	void SetSecondPointY(int y);

	int GetThirdPointX() const;
	void SetThirdPointX(int x);
	int GetThirdPointY() const;
	void SetThirdPointY(int y);

	void TriangleDecrease();
	void TriangleIncrease();

	void TriangleShifting(int direction);
private:
	int _firstPointX;
	int _firstPointY;
	int _secondPointX;
	int _secondPointY;
	int _thirdPointX;
	int _thirdPointY;
};

#endif