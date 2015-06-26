#include "Functions.h"
#include <string>

// ****************************************************************************
// ***  Interface of private fuctions
// ****************************************************************************

void MakePalindromAddingCharactersToTheRightSide(const StringType source, StringType destination);

// ****************************************************************************
// ***  Implementation of public fuctions
// ****************************************************************************

int StringLength(const StringType string)
{
	int length = 0;
	while (string[length] != 0)
	{
		length++;
	}
	return length;
}

void StringCopy(StringType destination, const StringType source)
{
	int index = 0;
	while ((destination[index] = source[index]) != 0)
	{
		index++;
	}
}

void StringConcatenation(StringType destination, const StringType source)
{
	int destIndex = StringLength(destination);
	int sourceIndex = 0;
	while ((destination[destIndex++] = source[sourceIndex++]) != 0);
}

int IndexOfSubstring(const StringType source, const StringType substring)
{
	int result = -1;
	int sourceLength = strlen(source);
	int substringLength = strlen(substring);
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

bool IsPalindrom(const StringType string)
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

void MakePalindrom(const StringType source, StringType destination)
{
	int sourceLength = strlen(source);
	if (0 == sourceLength)
		return;

	if (IsPalindrom(source))
	{
		strcpy(destination, source);
	}
	else
	{
		StringType rightPalindrom = "";
		MakePalindromAddingCharactersToTheRightSide(source, rightPalindrom);

		StringType revertedString = "";
		for (int i = 0; i < sourceLength; i++)
		{
			revertedString[i] = source[sourceLength - i - 1];
		}
		revertedString[sourceLength] = '\0';

		StringType leftPalindrom = "";
		MakePalindromAddingCharactersToTheRightSide(revertedString, leftPalindrom);

		int rightPalindromLength = strlen(rightPalindrom);
		int leftPalindromLength = strlen(leftPalindrom);
		if (rightPalindromLength > leftPalindromLength)
		{
			strcpy(destination, leftPalindrom);
		}
		else
		{
			strcpy(destination, rightPalindrom);
		}
	}
}

// ****************************************************************************
// ***  Implementation of private fuctions
// ****************************************************************************

void MakePalindromAddingCharactersToTheRightSide(const StringType source, StringType destination)
{
	int sourceLength = strlen(source);
	StringType localPalindrom = "";

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
			strcpy(destination, localPalindrom);
			break;
		}
	}
}
