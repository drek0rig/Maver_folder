#include "SupportTools.h"
#include <cstdio>

static const char kBooCalledMessage[] = "boo called!";
static const char kBoo2CalledMessage[] = "boo2 called!";

void boo()
{
	printf(kBooCalledMessage);
}

void boo2()
{
	printf(kBoo2CalledMessage);
}
