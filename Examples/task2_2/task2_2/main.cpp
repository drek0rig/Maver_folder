#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Getting value from user
	double xInDegrees;
	cout << "Input value of x in degrees = ";
	cin >> xInDegrees;

	double xInRadians = xInDegrees*3.14 / 180;

	// Calculating value of expression
	double result = 0;
	if (xInDegrees < 0)
	{
		result = 1;
	}
	else if (xInDegrees <= 180) 
	{
		result = cosf(xInRadians);
	}
	else 
	{
		result = -1;
	}

	cout << "Value of function = " << result << ";" << endl;

	return 0;
}