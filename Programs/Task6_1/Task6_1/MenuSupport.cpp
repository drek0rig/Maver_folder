#include "MenuSupport.h"

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

unsigned int maxStringLenght = 20;

typedef enum
{
	kReturStringLenghtChoiseType		= 1,
	kCopyOneStringToAnotheChoiseType	= 2,
	kStringConcatanationChoiseType		= 3,
	kSubstringIndexFindeChoiseType		= 4,
	kFindOutPolindromChoiseType			= 5,
	kMakePolindromChoiseType			= 6,
	kCleanScreanChoiseType				= 7,
	kExitProgramChoiseType				= 8,
	kCountMenuChoiseType				= kExitProgramChoiseType
} MenuChoiseType;

static const char kInputSymbolMessage[]							= ">> ";

// Menu messages
static const char kInformationMessage[]							= "Chose one from the next options.\n";
static const char kReturStringLenghtMessage[]					= "1. Return string lenght.\n";
static const char kCopyOneStringToAnotheMessage[]				= "2. Copy one string to anothe.\n";
static const char kSringConcatanationMessage[]					= "3. String concatanation.\n";
static const char kSubstringIndexFindeMessage[]					= "4. Find substring in aim string.\n";
static const char kFindOutPolindromMessage[]					= "5. Find out - is the aim string polindrom.\n";
static const char kMakePolindromMessage[]						= "6. Make from string minimum posible polindrom.\n";
static const char kCleanScreanMessage[]							= "7. Clean screan.\n";
static const char kExitProgramMessage[]							= "8. Exit the program.\n";

// Inside menu information messages
static const char kEnterAimStringMessage[]						= "\nEnter aim string for lenght calculation ";
static const char kLenghtOfAimStringMessage[]					= "\nLenght of aim string are %d.\n\n";

static const char kEnterDestinationStringMessage[]				= "\nEnter destination string for copying ";
static const char kEnterSourceStringMessage[]					= "\nEnter source string for copying ";
static const char kDestinationStringAfterCPInfoMessage[]		= "\nDestination string after copying are: %s\n\n";

static const char kEnterDestinationStringConcatenationMessage[]	= "\nEnter destination string for concatenation ";
static const char kEnterSourceStringConcatenationMessage[]		= "\nEnter source string for concatenation ";
static const char kDestinationStringAfterConcatInfoMessage[]	= "\nDestination string after concatenation are: %s\n\n";

static const char kEnterSourceStringForSearchingMessage[]		= "\nEnter source string for searching ";
static const char kEnterSearchingSubstringMessage[]				= "\nEnter searching substring ";
static const char kIndexResultInfoMessage[]						= "\nIndex of substring in sourse string is: %d.\n\n";

static const char kEnterStringForPolindromCheckMessage[]		= "\nEnter string for polindrom check ";
static const char kPolindromCheckMessage[]						= "\nNow we will check if a aim string is polindrom: ";
static const char kConfirmMessage[]								= "True\n\n";
static const char kDenialMessage[]								= "False\n\n";

static const char kEnterStringForPolindromMakeMessage[]			= "\nEnter string for making polindrom ";
static const char kResultPolindromMessage[]						= "\nResult polindrom is: %s\n\n";

static const char kExitConfirmationMessage[]					= "\nAre you sure?\n";

// Error messages
static const char kEnterCorrectValueMessage[]					= "\nPlease, enter correct value.\n\n";
static const char kEnterValueInRanseMessage[]					= "\nEnter value in range 1-%d.\n\n";
// ****************************************************************************
// ***  Interface of local fuctions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin();

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

MenuSupport::MenuSupport()
{
#ifdef SHOW_DEBUG_MESAAGES
	printf("MenuSupport constructor culled!\n");
#endif
	_userChoise = 0;
}

MenuSupport::~MenuSupport()
{
#ifdef SHOW_DEBUG_MESAAGES
	printf("MenuSupport destructor culled!\n");
#endif
}

void MenuSupport::runMenu()
{
	bool canExit = false;
	while (!canExit)
	{
		printMenuAndTakeChoise();
		if (_userChoise == 0)
			continue;

		switch (_userChoise)
		{
		case kReturStringLenghtChoiseType:
			{
				printf(kEnterAimStringMessage);
				printf(kInputSymbolMessage);

				char* ptrAimStringLenght = new char[maxStringLenght];
				gets_s(ptrAimStringLenght, maxStringLenght);

				int stringLenght = StringLength(ptrAimStringLenght);

				printf(kLenghtOfAimStringMessage, stringLenght);

				delete[] ptrAimStringLenght;
				_userChoise = 0;
				break;
			}
		case kCopyOneStringToAnotheChoiseType:
			{
				printf(kEnterDestinationStringMessage);
				printf(kInputSymbolMessage);
				char* ptrDestinationStringCopy = new char[maxStringLenght];
				gets_s(ptrDestinationStringCopy, maxStringLenght);

				printf(kEnterSourceStringMessage);
				printf(kInputSymbolMessage);
				char* ptrSourceStringCopy = new char[maxStringLenght];
				gets_s(ptrSourceStringCopy, maxStringLenght);

				StringCopy(ptrDestinationStringCopy, ptrSourceStringCopy);
				printf(kDestinationStringAfterCPInfoMessage, ptrDestinationStringCopy);

				delete[] ptrDestinationStringCopy;				
				delete[] ptrSourceStringCopy;
				_userChoise = 0;
				break;
			}
		case kStringConcatanationChoiseType:
			{
				printf(kEnterDestinationStringConcatenationMessage);
				printf(kInputSymbolMessage);
				char* ptrDestinationStringConcatenation = new char[maxStringLenght];
				gets_s(ptrDestinationStringConcatenation, maxStringLenght);

				printf(kEnterSourceStringConcatenationMessage);
				printf(kInputSymbolMessage);
				char* ptrSourceStringConcatenation = new char[maxStringLenght];
				gets_s(ptrSourceStringConcatenation, maxStringLenght);

				StringConcatenation(ptrDestinationStringConcatenation, ptrSourceStringConcatenation);
				printf(kDestinationStringAfterConcatInfoMessage, ptrDestinationStringConcatenation);

				delete[] ptrDestinationStringConcatenation;				
				delete[] ptrSourceStringConcatenation;
				_userChoise = 0;
				break;
			}
		case kSubstringIndexFindeChoiseType:
			{
				printf(kEnterSourceStringForSearchingMessage);
				printf(kInputSymbolMessage);
				char* ptrSourceStringForSearching = new char[maxStringLenght];
				gets_s(ptrSourceStringForSearching, maxStringLenght);

				printf(kEnterSearchingSubstringMessage);
				printf(kInputSymbolMessage);
				char* ptrSearchingSubstring = new char[maxStringLenght];
				gets_s(ptrSearchingSubstring, maxStringLenght);

				int index = IndexOfSubstring(ptrSourceStringForSearching, ptrSearchingSubstring);
				printf(kIndexResultInfoMessage, index+1);

				delete[] ptrSourceStringForSearching;				
				delete[] ptrSearchingSubstring;
				_userChoise = 0;
				break;
			}
		case kFindOutPolindromChoiseType:
			{
				printf(kEnterStringForPolindromCheckMessage);
				printf(kInputSymbolMessage);
				char* ptrStringPolindromCheck = new char[maxStringLenght];
				gets_s(ptrStringPolindromCheck, maxStringLenght);

				printf(kPolindromCheckMessage);
				if (IsPalindrom(ptrStringPolindromCheck))
				{
					printf(kConfirmMessage);
				}
				else
				{
					printf(kDenialMessage);
				}

				delete[] ptrStringPolindromCheck;
				_userChoise = 0;
				break;
			}
		case kMakePolindromChoiseType:
			{
				printf(kEnterStringForPolindromMakeMessage);
				printf(kInputSymbolMessage);
				char* ptrStringPolindromMake = new char[maxStringLenght];
				gets_s(ptrStringPolindromMake, maxStringLenght);

				char* ptrPolindrom = MakePalindrom(ptrStringPolindromMake);

				printf(kResultPolindromMessage, ptrPolindrom);
				delete[] ptrPolindrom;
				delete[] ptrStringPolindromMake;
				_userChoise = 0;
				break;
			}
		case kCleanScreanChoiseType:
			{
				system("cls");
				_userChoise = 0;
				break;
			}
		case kExitProgramChoiseType:
			{
				printf(kExitConfirmationMessage);
				printf(kInputSymbolMessage);
				char answerString[20];
				gets_s(answerString);

				int lenght = strlen(answerString);
				for (int i = 0; i < lenght; i++)
					answerString[i] = tolower(answerString[i]);

				if (strcmp(answerString, "y") == 0 || strcmp(answerString, "yes") == 0)
					canExit = true;				
				break;
			}
		default:
			{
				printf(kEnterCorrectValueMessage);
				break;
			}
		}
	}
	
}

void MenuSupport::printMenuAndTakeChoise()
{
	printf(kInformationMessage);
	printf(kReturStringLenghtMessage);
	printf(kCopyOneStringToAnotheMessage);
	printf(kSringConcatanationMessage);
	printf(kSubstringIndexFindeMessage);
	printf(kFindOutPolindromMessage);
	printf(kMakePolindromMessage);
	printf(kCleanScreanMessage);
	printf(kExitProgramMessage);
	printf(kInputSymbolMessage);

	int currentChoise;
	cin >> currentChoise;

	if (!MakeCheckForNumberInputFromCin())
	{
		printf(kEnterCorrectValueMessage);
	}
	else if (1 > currentChoise || currentChoise > kCountMenuChoiseType)
	{
		printf(kEnterValueInRanseMessage, kCountMenuChoiseType);
	}
	else _userChoise = currentChoise;
}

int MenuSupport::StringLength(const char* const string)
{
	int lenght = 0;
	while (string[lenght])  // мабуть я наркоман, але мені більше подобається така форма *(string + lenght)  :))
	{		
		lenght++;
	}
	return lenght;
}

void MenuSupport::StringCopy(char* destination, const char* const source)
{
	int index = 0;
	while (destination[index] = source[index])
		index++;
		
	destination[index] = '\0';
}

void MenuSupport::StringConcatenation(char* const destination, const char* const source)
{
	int index = 0;
	int destinationLength = StringLength(destination);
	while (destination[destinationLength++] = source[index++]);
		
	destination[destinationLength] = '\0';
}

int MenuSupport::IndexOfSubstring(const char* const source, const char* const substring)
{
	int result = -1;
	int sourceLength = StringLength(source);
	int substringLength = StringLength(substring);
	int lastPointCount = sourceLength - substringLength + 1;

	for (int startIndex = 0; startIndex < lastPointCount; startIndex++)
	{
		bool needStartNext = false;
		for (int substringIndex = 0; substringIndex < substringLength; substringIndex++)
		{
			if (source[startIndex + substringIndex] != substring[substringIndex])
			{
				needStartNext = true;
				break;
			}
		}
		if (!needStartNext)
		{
			result = startIndex;
			break;
		}
	}

	return result;
}

bool MenuSupport::IsPalindrom(const char* const string)
{
	bool result = false;
	int stringLenght = StringLength(string);

	char* tempStringBegin = new char[maxStringLenght];
	int index = 0;
	for(index = 0; index < stringLenght / 2; index++)
		tempStringBegin[index] = string[index];
	tempStringBegin[index] = '\0';

	char* tempStringEnd = new char[maxStringLenght];
	int tempIndex = stringLenght - 1;
	for(index = 0; index < stringLenght / 2; index++)
	{
		tempStringEnd[index] = string[tempIndex];
		tempIndex--;
	}
	tempStringEnd[index] = '\0';

	if(strcmp(tempStringBegin, tempStringEnd))
		result = false;
	else
		result = true;

	delete[] tempStringBegin;	
	delete[] tempStringEnd;
		
	return result;
}

char* MenuSupport::MakePalindrom(const char* const source)
{
	char* result = new char[maxStringLenght];
	StringCopy(result, source);


	if (!IsPalindrom(source))
	{
		int sourceLenght = StringLength(source);
		int iteretionNumber = 0;

		for (iteretionNumber = 0; iteretionNumber < sourceLenght; iteretionNumber++)
		{
			char* tempStringBegin = new char[maxStringLenght];
			char* tempStringEnd = new char[maxStringLenght];
				
			int index = 0;
			for (index = 0; index < iteretionNumber + 1; index++) 
			{
				tempStringBegin[index] = source[index];
			}
			tempStringBegin[index] = '\0';

			StringCopy(tempStringEnd, &source[iteretionNumber + 1]);

			if (IsPalindrom(tempStringBegin) && StringLength(tempStringBegin) > 1)
			{
				char* newEnd = new char[maxStringLenght];
				StringCopy(newEnd, tempStringEnd);

				StringRevers(tempStringEnd);
				StringCopy(result, tempStringEnd);

				int resultLenght = StringLength(result);
				for (int i = 0; tempStringBegin[i]; i++)
				{
					result[resultLenght] = tempStringBegin[i];
					resultLenght++;
				}
				result[resultLenght] = '\0';

				StringConcatenation(result, newEnd);
				delete[] newEnd;
				delete[] tempStringBegin;
				delete[] tempStringEnd;
				break;
			}
			else if (IsPalindrom(tempStringEnd))
			{
				StringRevers(tempStringBegin);
				StringConcatenation(result, tempStringBegin);
				delete[] tempStringBegin;
				delete[] tempStringEnd;
				break;
			}
			else
				delete[] tempStringBegin;
				delete[] tempStringEnd;
				continue;
		}
	}

	return result;
}

void MenuSupport::StringRevers(char* string)
{
	char* tempString = new char[maxStringLenght];
	int stringLenght = StringLength(string);
	
	int reversIndex = stringLenght - 1;
	int i = 0;
	for (i = 0; i < stringLenght; i++)
	{
		tempString[i] = string[reversIndex];
		reversIndex--;
	}
	tempString[i] = '\0';

	for (i = 0; i < stringLenght; i++)
	{
		string[i] = tempString[i];
	}
	string[i] = '\0';
}

bool MakeCheckForNumberInputFromCin()
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
	}
	return result;
}