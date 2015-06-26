#include "SupportTools.h"
#include <iostream>

using namespace std;

//#define GREETINGS_ANYKEY

static const char kInputSymbolMessage[]				= ">>";

#ifdef GREETINGS_ANYKEY
// Greetings messages
static const char kGreetingsmessage[]				= "Greetings, user!\n"
													  "This little program work whith strings.\n"
													  "And you take in this main role!:)\n"
													  "So..";
static const char kAnykeyConfirmation[]				= "Please, type anykey.\n";
static const char kWrongMessage[]					= "WRONG! (((\n";
static const char kSmartUserCanContinue[]			= "Srart user! U can continue. :)\n";

typedef enum
{
	kRightAnswer		= 1,
	kWrongAnswer		= 2
} AnswerToMainQuestion;
#endif

// Main function messages
static const char kInputFirstStringMassage[]		= "Input first string.\n";
static const char kInputSecondStringMassage[]		= "Input second string.\n";

static const char kFirstStringLenght[]				= "First string lenght is: %d\n";
static const char kSecondStringLenght[]				= "Second string lenght is: %d\n";

static const char kStringCopyMessage[]				= "Copy second string to first: %s\n";
static const char kStringConcatinationMessage[]		= "Concatination first and second string: %s\n";
static const char kIndexOfSubstringMessage[]		= "Index of substring in first string is: %d\n";
static const char kNewIndexOfSubstringMessage[]		= "New index of substring in first string is: %d\n";

static const char kPolindromCheckMessage[]			= "Now we will check if a first string is polindrom: ";
static const char kConfirmMessage[]					= "True\n";
static const char kDenialMessage[]					= "False\n";

static const char kPolidromCreation[]				= "And create a polindrom, if it isn`t: %s\n";

// Interface of functions
int GreetingsFunction();

int main()
{
#ifdef GREETINGS_ANYKEY
	int greetingsVariable = GreetingsFunction();
	if(greetingsVariable == kWrongAnswer){
		return -1;}
#endif

	//������� �� ������
	StringType firstString = "";
	printf(kInputFirstStringMassage);
	printf(kInputSymbolMessage);
	gets_s(firstString);

	StringType secondString = "";
	printf(kInputSecondStringMassage);
	printf(kInputSymbolMessage);
	gets_s(secondString);

	// ����������� ������� ����� � ����� ����� ������� ��������
	int firstStringLenght = StringLength11(&firstString[0]);
	printf(kFirstStringLenght, firstStringLenght);

	int secondStringLenght = StringLength(secondString);
	printf(kSecondStringLenght, secondStringLenght);

	//��������� ������ � ������
	//StringCopy(firstString, secondString);	// ������������� ��� �������� ��������� ��������
	printf(kStringCopyMessage, firstString);

	//��������� �� 1� ������ 2�
	//StringConcatenation(firstString, secondString);	// ������������� ��� �������� ��������� ��������
	printf(kStringConcatinationMessage, firstString);

	//����������� ������� �������� � �������� �����
	int substringIndex = IndexOfSubstring(firstString, secondString);
	printf(kIndexOfSubstringMessage, substringIndex);

	int substringIndexSecond = InEscapebleIndexOfSubstring(firstString, secondString, 0);
	printf(kNewIndexOfSubstringMessage, substringIndexSecond);
	
	// �������� �� ��������
	if(IsPalindrom(firstString))
	{
		printf(kPolindromCheckMessage);
		printf(kConfirmMessage);
	}
	else
	{
		printf(kPolindromCheckMessage);
		printf(kDenialMessage);
	}

	/* MakePalindrom(firstString, secondString);
	printf(kPolidromCreation, secondString); */
	
	MakeTinyPalindrom(firstString, secondString);
	printf(kPolidromCreation, secondString);

	return 0;
}

#ifdef GREETINGS_ANYKEY
int GreetingsFunction()
{
	printf(kGreetingsmessage);
	printf(kAnykeyConfirmation);

	StringType AnyKeyString = "";
	printf(kInputSymbolMessage);
	gets_s(AnyKeyString);

	int lenght = strlen(AnyKeyString);
	for(int i = 0; i < lenght; i++)
		AnyKeyString[i] = tolower(AnyKeyString[i]);

	if(strcmp(AnyKeyString, "anykey") != 0)
	{
		printf(kWrongMessage);
		return 2;
	}  //	break; �� ����� � ��������?
	else
	{
		printf(kSmartUserCanContinue);
		return 1;
	}	
}
#endif