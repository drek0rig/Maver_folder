#ifndef PROJECT_SUPPORT_H
#define PROJECT_SUPPORT_H
#pragma once

#include <stdlib.h>

// ****************************************************************************
// ***  Interface of public fuctions
// ****************************************************************************

int StringLength(const char* const string);
void StringCopy(char* const destination, const char* const source);
void StringConcatenation(char* const destination, const char* const source);
int IndexOfSubstring(const char* const source, const char* const substring);
bool IsPalindrom(const char* const string);
char* MakePalindrom(const char* const source);

#endif