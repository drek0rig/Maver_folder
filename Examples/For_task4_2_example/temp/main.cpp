#include <cstdio>
#include "SupportTools.h"
#include "SupportTools2.h"

static const char kMainCalledMessage[] = "main called!";

int main()
{
	printf(kMainCalledMessage);
	foo();
	boo();
	return 0;
}


