#include "MenuSupport.h"
#include <stdio.h>
#include <string>

//#define SHOW_MEMORY_ERRORS
#define NEED_FIND_LEAKS

#ifdef NEED_FIND_LEAKS
#include <crtdbg.h>
#endif

int main()
{
	int errorCode = 0;
	{
#ifdef SHOW_MEMORY_ERRORS

#define MEMORY_ERROR 1
#if 1 == MEMORY_ERROR
		// Wrong creation of dynamic string
		// Run app by CTRL-F5 in Debug version
		char buffer[] = "123456";
		int stringLength = strlen(buffer);

		char* tempString = new char[stringLength];
		strcpy(tempString, buffer);
		delete[] tempString;

#else if 2 == MEMORY_ERROR
		// This is extansion of previous example
		// Start from here debuging and watch to variables
		char someString1[5] = "1234";
		char someString2[5] = "abcd";
		strcpy(someString2, "zxcv-------------");

		int sizeOfStr1 = sizeof(someString1);
		int sizeOfStr2 = sizeof(someString2);
#endif

#endif

		errorCode = RunMainMenu();
	}

#ifdef NEED_FIND_LEAKS
    if (_CrtDumpMemoryLeaks())
    {
		printf("!!! There are some leaks. See 'Output' window in Visual Stusio.\n");
		getchar();
    }
#endif

	return errorCode;
}
