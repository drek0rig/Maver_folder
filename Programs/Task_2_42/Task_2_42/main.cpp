# include <iostream>
# include <math.h>

using namespace std;

int main()
{
	double x = 0;
	double y = 0;
	
	cout << "Enter number x:\t";
	cin >> x;
	cout << "Enter number y:\t";
	cin >> y;

	double z = 0;

	if(x > 0 && y > 0)
		z = (x + y)/(x * y + x*x*x);
	else if(x == 0)
		z = 3.14 * y;
	else if(y == 0) 
		z= x*x;
	else z = 1;

	cout << "Result z=" << z << endl;

	return 0;
}