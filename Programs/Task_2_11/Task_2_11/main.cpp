#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	double someNumber;
	cout << "Enter some number:";
	cin >> someNumber;

	double massive[5];
	massive[0] = 4;
	massive[1] = someNumber;
	massive[2] = someNumber / 0.125;
	massive[3] = someNumber * 0.125;
	massive[4] = 5;

	double maxElement = massive[0];
	// А далі піде порнографія :)
	if (maxElement < massive[1])
	{
		maxElement = massive[1];
		if (maxElement < massive[2])
		{
			maxElement = massive[2];
			if (maxElement < massive[3])
			{
				maxElement = massive[3];
				if (maxElement < massive[4])
				{
					maxElement = massive[4];
				}
			}
		}
	}
	

	cout << "\n\nMassive:\t" << massive[0] << "\t";
	cout << massive[1] << "\t";
	cout << massive[2] << "\t";
	cout << massive[3] << "\t";
	cout << massive[4] << "\t" <<endl;
	cout << "Max element:" << maxElement << endl; // Отриманого результату я зрозумів не до кінця

	return 0;
}