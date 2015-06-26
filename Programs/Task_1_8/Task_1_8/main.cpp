# include <iostream>
#define _USE_MATH_DEFINES
# include <math.h>

using namespace std;

double calcX1 (int c1, int d1)
{
	// Расчитываем х1, как больший корень квадратного уравнения. 
	return ( 0.5 * ( 3 + sqrt ( (double) 9 + 4*c1*d1 ) ) );
}

double calcX2 (int c2, int d2)
{
	// Расчитываем х2, как меньший корень квадратного уравнения.
	return ( 0.5 * ( 3 - sqrt ( (double) 9 + 4*c2*d2 ) ) );
}

int main()
{
	int c, d;
	cout << "Enter c: ";
	cin >> c;
	cout << "\nEnter d: ";
	cin >> d;
	
	double x1 = calcX1 (c, d), x2 = calcX2 (c, d);
	// Проверку какой из корней больше другого не делаем, хотя надо было бы :), в таком виде с помощью вспомагательных переменных
	/* if (x1_temp > x2_temp)
		 x1 = x1_temp;
		 x2 = x2_temp;
	 else
		 x1 = x2_temp;
		 x2 = x1_temp; 
	*/
	
	double result = abs ( pow ( sin ( abs (c * pow (x1,3) + d * pow (x2,2) - c*d) ), 3 ) / sqrt ( pow ( (c * pow (x1,3) + d * pow (x2,2) - x1), 2) + 3.14) );
	cout << "Result: " << result << endl;
	return 0;
}