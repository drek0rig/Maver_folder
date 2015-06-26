#include "SupportTools2.h"
#include <cstdio>

static const char kFooCalledMessage[] = "foo called!";

void foo()
{
	printf(kFooCalledMessage);
	boo();
}