#ifndef PROJECT_SUPPORT_H
#define PROJECT_SUPPORT_H
#pragma once

#include <stdlib.h>

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

//#define SHOW_DEBUG_MESSAGES

static const unsigned int kMaxStringLength = 80;
extern const unsigned int kMaxNameLength;

// typedef	char StringType[kMaxStringLength];

// ****************************************************************************
// ***  Interface of fuctions
// ****************************************************************************

void SetupRandomFunctionality();
void MakeStingLowerCase(char* outString);

#endif