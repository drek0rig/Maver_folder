#ifndef FUNCTIONS_AND_CLASSES_H
#define FUNCTIONS_AND_CLASSES_H

class Rectangle
{
public:
	// Access methods
	int GetLeftDownAngleX ();
	void SetLeftDownAngleX (int coordinateX);

	int GetLeftDownAngleY ();
	void SetLeftDownAngleY (int coordinateY);

	int GetWidth ();
	void SetWidth (int width);

	int GetHeight ();
	void SetHeight (int height);

	// Methods
	void WidthDecrease();
	void HeightDecrease();
	void WidthIncrease();
	void HeightIncrease();

	void RectangleShifting(int direction);
private:
	int _lefDownAnglX;
	int _lefDownAnglY;
	int _width;
	int _height;
};

#endif