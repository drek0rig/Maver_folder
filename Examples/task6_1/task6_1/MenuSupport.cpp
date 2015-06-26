#include "MenuSupport.h"
#include "SupportTools.h"
#include <iostream>
#include <string>

using namespace std;

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kInputSymbolMessage[]					= ">> ";

// Messages of menu
static const char kMainMenuMessage[]					= "\nChoise action:\n"
														  "1. Check 'StringLength' function;\n"
														  "2. Check 'StringCopy' function;\n"
														  "3. Make one string from two;\n"
														  "4. Find index of substring;\n"
														  "5. Check on palindrom;\n"
														  "6. Make palindrom;\n"
														  "7. Exit;\n";

static const char kInputSomeStringMessage[]				= "\nInput some string:\n";
static const char kInputSecondSomeStringMessage[]		= "Input second some string:\n";
static const char kLengthOfInputStringMessage[]			= "The length of the input string = %i\n";
static const char kResultStringCopyingMessage[]			= "The result string copying = \"%s\"\n";
static const char kResultStringMergingMessage[]			= "The result string merging = \"%s\"\n";
static const char kInputSubstringForSearchMessage[]		= "Input substring for search:\n";
static const char kFirstEnteringOfSubstringMessage[]	= "Index of first entering for substring: %i\n";
static const char kInputStringIsOrNotPalindromMessage[]	= "Input string %s palindrom\n";
static const char kIsMessage[]							= "is";
static const char kIsntMessage[]						= "isn't";
static const char kCompletedPalindromMessage[]			= "Completed palindrom '%s'\n";

// Error messages
static const char kEnterCorretChoiseValueErrorMessage[]			= "Please enter corret choise value.\n";
static const char kThereIsNoCorrespondingOptionErrorMessage[]	= "There is no corresponding option for you choise!\n";

typedef enum
{
	kGetStringLengthMainMenuChoiseType		= 1,
	kMakeStringCopyMainMenuChoiseType		= 2,
	kMakeOneStringMainMenuChoiseType		= 3,
	kFindSubstringMainMenuChoiseType		= 4,
	kCheckOnPalindromMainMenuChoiseType		= 5,
	kMakePalindromMainMenuChoiseType		= 6,
	kExitProgramMainMenuChoiseType			= 7
} MainMenuChoiseType;

// ****************************************************************************
// ***  Interface of private functions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[]);

// ****************************************************************************
// ***  Implementation of public functions
// ****************************************************************************

int RunMainMenu()
{   MakePalindrom(NULL);
	int const kMaxStringSize = 150;
	char* buffer = new char[kMaxStringSize];
	bool canExit = false;
	while (!canExit)
	{
		printf(kMainMenuMessage);
		printf(kInputSymbolMessage);
		int currentChoise;

		cin >> currentChoise;
		if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
			continue;

		if (currentChoise < kGetStringLengthMainMenuChoiseType &&
				currentChoise > kExitProgramMainMenuChoiseType)
		{
			printf(kThereIsNoCorrespondingOptionErrorMessage);
			continue;
		}

		switch (currentChoise)
		{
			case kGetStringLengthMainMenuChoiseType:
			{
				printf(kInputSomeStringMessage);
				gets(buffer);

				printf(kLengthOfInputStringMessage, StringLength(buffer));
				break;
			}
			case kMakeStringCopyMainMenuChoiseType:
			{
				printf(kInputSomeStringMessage);
				gets(buffer);

				char* copiedString = new char[strlen(buffer) + 1];
				StringCopy(copiedString, buffer);
				printf(kResultStringCopyingMessage, copiedString);
				delete[] copiedString;
				break;
			}
			case kMakeOneStringMainMenuChoiseType:
			{
				printf(kInputSomeStringMessage);
				gets(buffer);

				char* secondString = new char[kMaxStringSize];
				printf(kInputSecondSomeStringMessage);
				gets(secondString);

				StringConcatenation(buffer, secondString);
				delete[] secondString;

				printf(kResultStringMergingMessage, buffer);
				break;
			}
			case kFindSubstringMainMenuChoiseType:
			{
				printf(kInputSomeStringMessage);
				gets(buffer);

				char* secondString = new char[kMaxStringSize];
				printf(kInputSubstringForSearchMessage);
				gets(secondString);

				printf(kFirstEnteringOfSubstringMessage, IndexOfSubstring(buffer, secondString));
				delete[] secondString;
				break;
			}
			case kCheckOnPalindromMainMenuChoiseType:
			{
				printf(kInputSomeStringMessage);
				gets(buffer);

				printf(kInputStringIsOrNotPalindromMessage, IsPalindrom(buffer) ? kIsMessage : kIsntMessage);
				break;
			}
			case kMakePalindromMainMenuChoiseType:
			{
				// Some test strings:
				// aaabccba
				// aaabcba
				// aa
				// a
				printf(kInputSomeStringMessage);
				gets(buffer);

				char* secondString = MakePalindrom(buffer);
				printf(kCompletedPalindromMessage, secondString);
				delete[] secondString;
				break;
			}
			case kExitProgramMainMenuChoiseType:
			{
				canExit = true;
				break;
			}
		}
	}
	delete[] buffer;
	return 0;
}

// ****************************************************************************
// ***  Implementation of private functions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[])
{
	bool result = false;
	if (!cin.fail())
	{
		// If we type next '20sdfgsdsefg' string,
		// we need clear buffer that contain value after '20'
		cin.sync(); 
		result = true; // It's a normal value
	}
	else 
	{
		// Here we input something like that 'sdfgdsf20.5dsf'
		cin.clear(); // remove error flags
		cin.ignore();
		cin.sync(); 
		printf(inErrorMessage);
	}
	return result;
}
