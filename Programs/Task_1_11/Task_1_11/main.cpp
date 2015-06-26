# include <iostream>
#define _USE_MATH_DEFINES
# include <math.h>

using namespace std;

double heightA (int a1, int b1, int c1, float p1)
{
	// Определение высоты к стороне а
	return ( 2* sqrt ( (double) p1 * (p1-a1) * (p1-b1) * (p1-c1) ) / a1);
}

double heightB (int a2, int b2, int c2, float p2)
{
	// Определение высоты к стороне b
	return ( 2* sqrt ( (double) p2 * (p2-a2) * (p2-b2) * (p2-c2) ) / b2);
}

double heightC (int a3, int b3, int c3, float p3)
{
	// Определение высоты к стороне а
	return ( 2* sqrt ( (double) p3 * (p3-a3) * (p3-b3) * (p3-c3) ) / c3);
}

double medianA (int a4, int b4, int c4)
{
	// Определение медианы к стороне а
	return ( sqrt ( (double) 2 * (b4*b4 + c4*c4) - a4*a4) / 2);
}

double medianB (int a5, int b5, int c5)
{
	// Определение медианы к стороне b
	return ( sqrt ( (double) 2 * (a5*a5 + c5*c5) - b5*b5) / 2);
}

double medianC (int a6, int b6, int c6)
{
	// Определение медианы к стороне с
	return ( sqrt ( (double) 2 * (b6*b6 + a6*a6) - c6*c6) / 2);
}

int main ()
{
	int a, b, c;
	cout << "Enter the side a: ";
	cin >> a;
	cout << "\nEnter the side b: ";
	cin >> b;
	cout << "\nEnter the side c: ";
	cin >> c;

	float p = (a+b+c)/2; // Определение полупериметра для формулы высоты

	double Ha = heightA (a,b,c,p);
	double Hb = heightB (a,b,c,p);
	double Hc = heightC (a,b,c,p);
	
	double Ma = medianA (a,b,c);
	double Mb = medianB (a,b,c);
	double Mc = medianC (a,b,c);

	cout << "\nHeight to side a: " << Ha << endl;
	cout << "Height to side b: " << Hb << endl;
	cout << "Height to side c: " << Hc << endl;

	cout << "Median to side a: " << Ma << endl;
	cout << "Median to side b: " << Mb << endl;
	cout << "Median to side c: " << Mc << endl;

	return 0;
}