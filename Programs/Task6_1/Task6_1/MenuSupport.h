#ifndef MENU_SUPPORT_H
#define MENU_SUPPORT_H
#pragma once

#include <iostream>

using namespace std;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class MenuSupport
{
public:
	MenuSupport();
	~MenuSupport();
	void runMenu();

private:
	void printMenuAndTakeChoise();

	int StringLength(const char* const string);
	void StringCopy(char* destination, const char* const source);
	void StringConcatenation(char* const destination, const char* const source);
	int IndexOfSubstring(const char* const source, const char* const substring);
	bool IsPalindrom(const char* const string);
	char* MakePalindrom(const char* const source);

	void StringRevers(char* string);

	int _userChoise;
};
#endif