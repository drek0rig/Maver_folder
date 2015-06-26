#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Declaration of variables
	double x = 0;
	double y = 0;
	double z = 0;
	double numerator, divider;

	// Getting value from user
	cout << "Input value of x = ";
	cin >> x;
	cout << "Input value of y = ";
	cin >> y;
	cout << "Input value of z = ";
	cin >> z;

	// Calculating value of a
	numerator = sqrt(fabsf(x - 1)) - powf(fabsf(y), 1.0/3);
	divider = 1 + x*x / 2.0 + powf(y, 2) / 2;
	cout << "Value of a = " << numerator / divider << ";" << endl;

	// Calculating value of b
	double b = atanf(z) + exp(-(x+3));
	b *= x;
	cout << "Value of b = " << b << ";" << endl;

	return 0;
}