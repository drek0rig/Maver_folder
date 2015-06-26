#include "SupportTools.h"
#include <string>

// ****************************************************************************
// ***  Interface of private fuctions
// ****************************************************************************

char* MakePalindromAddingCharactersToTheRightSide(const char* const source);

// ****************************************************************************
// ***  Implementation of public fuctions
// ****************************************************************************

int StringLength(const char* const string)
{
	int length = 0;
	while (*(string + length) != 0)
	{
		length++;
	}
	return length;
}

void StringCopy(char* const destination, const char* const source)
{
	int index = 0;
	while ((*(destination + index) = *(source + index)) != 0)
	{
		index++;
	}
}

void StringConcatenation(char* const destination, const char* const source)
{
	int destIndex = StringLength(destination);
	int sourceIndex = 0;
	while ((*(destination + destIndex++) = *(source + sourceIndex++)) != 0);
}

int IndexOfSubstring(const char* const source, const char* const substring)
{
	int result = -1;
	int sourceLength = strlen(source);
	int substringLength = strlen(substring);
	int startPointCount = sourceLength - substringLength + 1;

	for (int startIndex = 0; startIndex < startPointCount; startIndex++)
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
			result = startIndex;
	}

	return result;
}

bool IsPalindrom(const char* const string)
{
	int stringLength = strlen(string);
	bool result = stringLength ? true : false;
	int iterCount = stringLength / 2;
	for (int i = 0; i < iterCount; i++)
	{
		if (string[i] != string[stringLength - i - 1])
		{
			result = false;
			break;
		}
	}

	return result;
}

char* MakePalindrom(const char* const source)
{
	int sourceLength = strlen(source);
	char* result = NULL;
	if (0 == sourceLength)
	{
		return result;
	}
	else if (IsPalindrom(source))
	{
		result = new char[sourceLength + 1];
		strcpy(result, source);
	}
	else
	{
		char* rightPalindrom = MakePalindromAddingCharactersToTheRightSide(source);

		char* revertedString = new char[sourceLength + 1];
		for (int i = 0; i < sourceLength; i++)
		{
			revertedString[i] = source[sourceLength - i - 1];
		}
		revertedString[sourceLength] = '\0';

		char* leftPalindrom = MakePalindromAddingCharactersToTheRightSide(revertedString);
		int rightPalindromLength = strlen(rightPalindrom);
		int leftPalindromLength = strlen(leftPalindrom);
		int resultLength;
		char* tempPtr;
		if (rightPalindromLength > leftPalindromLength)
		{
			tempPtr = leftPalindrom;
			resultLength = leftPalindromLength;
		}
		else
		{
			tempPtr = rightPalindrom;
			resultLength = rightPalindromLength;
		}
		
		result = new char[resultLength + 1];
		strcpy(result, tempPtr);

		delete[] revertedString;
		delete[] rightPalindrom;
		delete[] leftPalindrom;
	}

	return result;
}

// ****************************************************************************
// ***  Implementation of private fuctions
// ****************************************************************************

char* MakePalindromAddingCharactersToTheRightSide(const char* const source)
{
	int sourceLength = strlen(source);
	int maxResultLength = 2*sourceLength - 1;
	char* result = new char[maxResultLength + 1];
	char* localPalindrom = new char[maxResultLength + 1];

	strcpy(localPalindrom, source);
	for (int iterCount = 1; iterCount < sourceLength; iterCount++)
	{
		for (int charCopyCount = iterCount, i = 0; charCopyCount > 0; charCopyCount--, i++)
		{
			localPalindrom[sourceLength + i] = localPalindrom[charCopyCount - 1];
		}
		localPalindrom[sourceLength + iterCount] = '\0';

		if (IsPalindrom(localPalindrom))
		{
			strcpy(result, localPalindrom);
			break;
		}
	}
	delete[] localPalindrom;

	return result;
}