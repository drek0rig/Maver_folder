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

void TolowerString(StringType aimString, StringType outputString)
{
	int lenght = strlen(aimString);
	for (int i = 0; i < lenght; i++)
		outputString[i] = tolower(aimString[i]);
}