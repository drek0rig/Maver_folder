#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

double numerator(int x1, int y1)
{
	return sqrt(abs((double)x1 - 1)) - pow(abs(y1), 1.0/3.0);
}

double denominator(int x2, int y2)
{
	return (1 + pow( (double)x2, 2) / 2 + pow( (double)y2, 2) / 4);
}

double calculateB(int x3, int z3)
{
	return (x3 * (atan ((double)z3) + pow (M_E, -(x3+3) )));
}

int main()
{
	int x, y, z;
	cout << "Enter x:";
	cin >> x;
	cout << "\nEnter y:";
	cin >> y;
	cout << "\nEnter z:";
	cin >> z;

	double a = numerator (x, y) / denominator (x, y);
	cout << "\na=" << a << endl;

	double b = calculateB (x, z);
	cout << "\nb=" << b << endl;
	return 0;
}