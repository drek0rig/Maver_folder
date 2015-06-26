#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

static const unsigned int kMaxStringLength = 80;
typedef		char StringType[kMaxStringLength];

// ****************************************************************************
// ***  Interface of public fuctions
// ****************************************************************************

int StringLength(const StringType string);
void StringCopy(StringType destination, const StringType source);
void StringConcatenation(StringType destination, const StringType source);
int IndexOfSubstring(const StringType source, const StringType substring);
bool IsPalindrom(const StringType string);
void MakePalindrom(const StringType source, StringType destination);

#endif