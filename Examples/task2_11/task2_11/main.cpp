#include <iostream>

using namespace std;

static const bool kUseDefaultValue = true;

int main()
{
	// Declaration of variables
	double massive[5] = {2, 3, 0, 10, -1};

	if (!kUseDefaultValue)
	{
		// Getting value from user
		cout << "Input value for massive[1] = ";
		cin >> massive[0];
		cout << "Input value for massive[2] = ";
		cin >> massive[1];
		cout << "Input value for massive[3] = ";
		cin >> massive[2];
		cout << "Input value for massive[4] = ";
		cin >> massive[3];
		cout << "Input value for massive[5] = ";
		cin >> massive[4];
	}

	// Finding the max value
	double maxValue = massive[0];
	if (maxValue < massive[1]) 
	{
		maxValue = massive[1];
	} 
	if (maxValue < massive[2])
	{
		maxValue = massive[2];
	}
	if (maxValue < massive[3]) 
	{
		maxValue = massive[3];
	}
	if (maxValue < massive[4]) 
	{
		maxValue = massive[4];
	}

	cout << "Maximum value in massive is " << maxValue << ";" << endl;

	return 0;
}