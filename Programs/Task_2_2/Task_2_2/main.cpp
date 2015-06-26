#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	double x;
	cout << "Enter x:";
	cin >> x;
	
	double y;
	if (x < 0)
	{	
		y = 1;
	}
	else if (x >= 0 && x <= M_PI)
	{
		y = cos(x);
	}
	else if (x > M_PI)
	{
		y = -1;
	}
	
	cout << "y is: " << y << endl;
	return 0;
}