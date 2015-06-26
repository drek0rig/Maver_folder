#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double x;
	double y;

	// Getting value from user
	cout << "Input value of x = ";
	cin >> x;
	cout << "Input value of y = ";
	cin >> y;

	// Calculating value of expression
	double result = 1;
	if (x > 0 && y > 0)
	{
		result = (x + y) / x*y + powf(x, 3);
	} 
	else if (x == 0) 
	{
		result = 3.14*y;
	}
	else if (y == 0) 
	{
		result = x*x;
	}

	cout << "Value of function = " << result << ";" << endl;

	return 0;
}