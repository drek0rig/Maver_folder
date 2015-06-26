#include "SupportTools.h"
#include <ctime>
#include <stdlib.h>

bool isFirstLaunch = true;

int RandomNumberReturn(unsigned int begin, unsigned int end)
{
	int midle = end - begin + 1;
	if (isFirstLaunch)
	{
		srand(time(NULL));
		isFirstLaunch = false;
	}
	return rand() % midle + begin;
}
