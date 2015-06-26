#include "MenuSupport.h"
#include <crtdbg.h>

int main()
{
	{
		MenuSupport mainMenu;
		mainMenu.runMenu();
	}

	if (_CrtDumpMemoryLeaks())
	{
		printf("Warning!!! There are some leaks.\n");
		getchar();
	}

	return 0;
}