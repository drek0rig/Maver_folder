#ifndef SUPPORT_TOOLS_H
#define SUPPORT_TOOLS_H
#include <stdio.h>
#include <ctype.h>
#include <cstring>

//  ************************************************************
//  ***  Constants and types
//  ************************************************************

static const unsigned int kMaxStringLength = 20;
typedef		char StringType[kMaxStringLength];

static const unsigned int kMaxProductRange = 20;
static const unsigned int kMaxShopRange = 15;

static const int matrixSize = 6;

int RandomNumberReturn(unsigned int begin, unsigned int end);
void TolowerString(StringType aimString, StringType outputString);

#endif