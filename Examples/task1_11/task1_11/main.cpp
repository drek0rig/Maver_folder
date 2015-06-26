#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Declaration of variables
	double sideA = 0;
	double sideB = 0;
	double sideC = 0;

	// Getting value from user
	cout << "Input value of side A = ";
	cin >> sideA;
	cout << "Input value of side B = ";
	cin >> sideB;
	cout << "Input value of side C = ";
	cin >> sideC;

	// Calculating semiperimeter for triangle
	double semiperimeter = (sideA + sideB + sideC) / 2.0f;

	// Calculating part of formula for height with three sides
	double partOfFormula = sqrtf(semiperimeter*(semiperimeter - sideA)*(semiperimeter - sideB)*(semiperimeter - sideC));

	cout << "Value of height to side A = " << 2*partOfFormula / sideA << ";" << endl;
	cout << "Value of height to side B = " << 2*partOfFormula / sideB << ";" << endl;
	cout << "Value of height to side C = " << 2*partOfFormula / sideC << ";" << endl;

	// Calculating median to side A
	double a = sideB;
	double b = sideC;
	double c = sideA;
	double median = sqrtf(2*a*a + 2*b*b - c*c) / 2;
	cout << "Value of median to side A = " << median << ";" << endl;

	// Calculating median to side B
	a = sideA;
	b = sideC;
	c = sideB;
	median = sqrtf(2*a*a + 2*b*b - c*c) / 2;
	cout << "Value of median to side B = " << median << ";" << endl;

	// Calculating median to side C
	a = sideA;
	b = sideB;
	c = sideC;
	median = sqrtf(2*a*a + 2*b*b - c*c) / 2;
	cout << "Value of median to side C = " << median << ";" << endl;

	return 0;
}