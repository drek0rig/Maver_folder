#ifndef SUPPORT_TOOLS_H
#define SUPPORT_TOOLS_H

// Constans and types
static const unsigned int kMaxStringLength = 80;
typedef		char StringType[kMaxStringLength];

// Interface of functions
int StringLength11(char *string);
int StringLength(const StringType string);

void StringCopy(StringType destination, const StringType source);

void StringConcatenation(StringType destination, const StringType source);

int IndexOfSubstring(const StringType source, const StringType substring);
int InEscapebleIndexOfSubstring(const StringType source, const StringType substring, int index);

bool IsPalindrom(const StringType string);

void MakePalindrom(const StringType source, StringType destination);
void MakeTinyPalindrom(const StringType source, StringType destination);

// Support function
void StringRevers(StringType string);

#endif