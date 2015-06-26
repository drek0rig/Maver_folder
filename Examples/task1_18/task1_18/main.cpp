#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Declaration of variables
	double x = 0;
	double result = 0; 

	// Getting value from user
	cout << "Input value of x = ";
	cin >> x;

	// Calculating value of expression
	result = x - powf(sinf(x) + 1, 2);
	result += x*x*(sinf(x) - 1);
	result *= 3.6;
	result += (x + 1) / (x - 1);

	cout << "Value of expression = " << result << ";" << endl;

	return 0;
}