#include "SupportTools.h"
#include <iostream>

int StringLength11(char *string)
{
	int count;
	for (count = 0; *string != '\0'; string++)
		count++;
	
	return count;
}

int StringLength(const StringType string)
{
	int count = 0;
	while(string[count] != '\0')
		count++;

	return count;
}

void StringCopy(StringType destination, const StringType source)
{
	int iteration = 0;
	while(destination[iteration] = source[iteration])
		iteration++;	
}

void StringConcatenation(StringType destination, const StringType source)
{
	int destinationLenght = StringLength(destination);
	int iteration = 0;
	while(destination[destinationLenght] = source[iteration])
	{
		destinationLenght++;
		iteration++;
	}	
}

int IndexOfSubstring(const StringType source, const StringType substring)
{
	int substringLenght = StringLength(substring);
	int index = 0;
	while(source[index] != substring[0])
		index++;
	
	StringType tempString;
	int tempStringIndex = 0;
	for(int j = index; j < index + substringLenght; j++)
	{
		tempString[tempStringIndex] = source[j];
		tempStringIndex++;
	}
	tempString[tempStringIndex] = '\0';

	if(strcmp(tempString, substring))
		return -1;
	else
		return index;
}

int InEscapebleIndexOfSubstring(const StringType source, const StringType substring, int index)
{
	/* int substringLenght = StringLength(substring);
		
	StringType tempString;
	int i = 0;
	for(i = 0; i < substringLenght; i++)
	{
		tempString[i] = source[i];
	}
	tempString[i] = '\0';

	if(strcmp(tempString, source))
	{
		index++;
		int idexSubSubstring = InEscapebleIndexOfSubstring(&source[index], substring);
	}
	else
		return ++index;

	return index; */
	int resaltIndex = index;
	if(source[resaltIndex])
	{
		int substringLenght = StringLength(substring);

		while(source[resaltIndex] != substring[0] && source[resaltIndex] != '\0')
			resaltIndex++;

		StringType tempString;
		int tempStringIndex = 0;
		for(int j = resaltIndex; j < resaltIndex + substringLenght; j++)
		{
			tempString[tempStringIndex] = source[j];
			tempStringIndex++;
		}
		tempString[tempStringIndex] = '\0';

		if(strcmp(tempString, substring))
			return InEscapebleIndexOfSubstring(source, substring, ++resaltIndex);
		else
			return resaltIndex;
	}
	else
	return -1;
}

bool IsPalindrom(const StringType string)
{
	bool result = false;
	int stringLenght = StringLength(string);

	StringType tempStringBegin;
	int index = 0;
	for(index = 0; index < stringLenght / 2; index++)
		tempStringBegin[index] = string[index];
	tempStringBegin[index] = '\0';

	StringType tempStringEnd;
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
	
	return result;
}

void MakePalindrom(const StringType source, StringType destination)
{
	StringCopy(destination, source);
	
	if (!IsPalindrom(source))
	{
		StringType tempString;
		int sourceLenght = StringLength(source);
		int backIndex = sourceLenght - 1;
		int index = 0;

		for (index = 0; index < sourceLenght; index++)
		{
			tempString[index] = source[backIndex];
			backIndex--;
		}
		tempString[index] = '\0';
				
		StringConcatenation(destination, source);
	}
}

void MakeTinyPalindrom(const StringType source, StringType destination)
{
	StringCopy(destination, source);

	if (!IsPalindrom(source))
	{
		int sourceLenght = StringLength(source);
		int iteretionNumber = 0;

		for (iteretionNumber = 0; iteretionNumber < sourceLenght; iteretionNumber++)
		{
			StringType tempStringBegin, tempStringEnd;
			int index = 0;
			for (index = 0; index < iteretionNumber + 1; index++) 
			{
				tempStringBegin[index] = source[index];
			}
			tempStringBegin[index] = '\0';

			StringCopy(tempStringEnd, &source[iteretionNumber + 1]);

			if (IsPalindrom(tempStringBegin) && StringLength(tempStringBegin) > 1)
			{
				StringType newEnd;
				StringCopy(newEnd, tempStringEnd);

				StringRevers(tempStringEnd);
				StringCopy(destination, tempStringEnd);

				int destinationLenght = StringLength(destination);
				for (int i = 0; tempStringBegin[i]; i++)
				{
					destination[destinationLenght] = tempStringBegin[i];
					destinationLenght++;
				}
				destination[destinationLenght] = '\0';

				StringConcatenation(destination, newEnd);
				break;
			}
			else if (IsPalindrom(tempStringEnd))
			{
				StringRevers(tempStringBegin);
				StringConcatenation(destination, tempStringBegin);
				break;
			}
			else
				continue;
		}
	}
}

void StringRevers(StringType string)
{
	StringType tempString;
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