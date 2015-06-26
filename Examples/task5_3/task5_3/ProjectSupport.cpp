#include "ProjectSupport.h"
#include <ctime>
#include <string>

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

static bool isRandomFunctionSetuped = false;

// ****************************************************************************
// ***  Implementation of local fuctions
// ****************************************************************************

void SetupRandomFunctionality()
{
	if (!isRandomFunctionSetuped)
	{
		srand((unsigned int)time(NULL));  // Setup random range
		isRandomFunctionSetuped = true;
	}
}

void MakeStingLowerCase(StringType outString)
{
	int strLength = strlen(outString);
	for (int i = 0; i < strLength; i++)
	{
		outString[i] = tolower(outString[i]);
	}
}