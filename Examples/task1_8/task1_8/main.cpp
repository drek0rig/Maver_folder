#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Declaration of variables
	double inputC = 0;
	double inputD = 0;

	// Getting value from user
	cout << "Input value of c = ";
	cin >> inputC;
	cout << "Input value of d = ";
	cin >> inputD;

	double a = 1;
	double b = -3;
	double c = -inputC*inputD;

	// Calculating discriminant of x*x - 3x - cd = 0
	double sqrtDiscriminant = sqrt(b*b - 4*a*c);
	
	// Calculating value of x1 and x2
	double x1 = (-b - sqrtDiscriminant) / (2 * a);
	double x2 = (-b + sqrtDiscriminant) / (2 * a);

	double numerator, divider;
	numerator = fabsf(inputC*powf(x1, 3) + inputD*x2*x2 - inputC*inputD);
	numerator = powf(sinf(numerator), 3);
	divider = sqrt(powf(inputC*powf(x1, 3) + inputD*x2*x2 - x1, 2) + 3.14);

	cout << "Value of expression = " << fabsf(numerator / divider) << ";" << endl;

	return 0;
}