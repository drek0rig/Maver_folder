#include "Nozdormu.h"
#include <crtdbg.h>

int main()
{
	{
		Nozdormu();
	}

	if (_CrtDumpMemoryLeaks())
	{
		printf("\n\nWarning!!! There are some leaks.\n");
		getchar();
	}

	return 0;
}