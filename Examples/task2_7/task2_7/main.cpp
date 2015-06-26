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

	if (sideA <= 0 || sideB <= 0 || sideC <= 0)
	{
		cout << "You must input positive value" << endl;
	} 
	else if (sideA + sideB <= sideC || 
			 sideA + sideC <= sideB || 
			 sideB + sideC <= sideA) 
	{
		cout << "Triangle with current sides can't be constructed" << endl;
	}
	else if (sideA == sideB && sideB == sideC) 
	{
		cout << "Triangle with current sides is equilateral" << endl;
	}
	else if (sideA == sideB || sideB == sideC || sideA == sideC) 
	{
		cout << "Triangle with current sides is isosceles" << endl;
	}
	else
	{
		cout << "Triangle with current sides is usual" << endl;
	}

	return 0;
}