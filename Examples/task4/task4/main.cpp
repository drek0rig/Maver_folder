#include "SupportTools.h"
#include <iostream>

using namespace std;

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kInputSymbolMessage[]				= ">> ";
static const char kDisableStateSymbolMessage[]		= "-- ";

// Messages of main menu
static const char kChoiseActionMessage[]			= "\nChoise action:\n";
static const char kInputMatrixMessage[]				= "1. Input matrix;\n";
static const char kPrintMatrixMessage[]				= "2. Print matrix;\n";
static const char kSetupMatrixToZeroMessage[]		= "3. Setup matrix to zero;\n";
static const char kMakeSortForMatrixMessage[]		= "4. Make sort for matrix;\n";
static const char kShiftMatrixMessage[]				= "5. Shift matrix;\n";
static const char kClearScreenMessage[]				= "6. Clear screen;\n";
static const char kExitProgramMessage[]				= "7. Exit;\n";

// Messages of sub menu 1
static const char kSubMenu1Message[]				= "\nHow to setup matrix elements?\n"
													  "1. random;\n"
													  "2. by keyboard;\n";
static const char kInputCountOfRowsMessage[]		= "Input count of rows (1-%i):\n";
static const char kInputCountOfColumnsMessage[]		= "Input count of columns (1-%i):\n";

// Messages of sub menu 4
static const char kHowMakeSortOfMatrixMessage[]		= "How make sort of matrix?\n"
													  "1. by ascending;\n"
													  "2. by descending;\n";

// Messages of sub menu 5
static const char kInputShiftCountMessage[]			= "How many we need shift elements (Positive value shifts "
													  "element to the right, \nnegative - to the left):\n";

// Messages of sub menu 7
static const char kConfirmExitMessage[]				= "Are you sure?\n";

// Error messages
static const char kYouNeedSetupMatrixFirstlyErrorMessage[]		= "You must first setup matrix from option one, before use this option!\n";
static const char kThereIsNoCorrespondingOptionErrorMessage[]	= "There is no corresponding option for you choise!\n";
static const char kEnterCorretChoiseValueErrorMessage[]			= "Please enter corret choise value.\n";
static const char kEnterCorretIntValueErrorMessage[]			= "Please enter an integer value.\n";
static const char kIncorrectRangeValueErrorMessage[]			= "You should input value in range (1-%i).\n";

typedef enum
{
	kInputMatrixMainMenuChoiseType			= 1,
	kPrintMatrixMainMenuChoiseType			= 2,
	kSetupMatrixToZeroMainMenuChoiseType	= 3,
	kMakeSortForMatrixMainMenuChoiseType	= 4,
	kShiftMatrixMainMenuChoiseType			= 5,
	kClearScreenMainMenuChoiseType			= 6,
	kExitProgramMainMenuChoiseType			= 7
} MainMenuChoiseType;

typedef enum
{
	kInputRandomSubMenu1ChoiseType			= 1,
	kInputByKeyboardSubMenu1ChoiseType		= 2
} SubMenu1ChoiseType;

// ****************************************************************************
// ***  Interface of functions
// ****************************************************************************

int MainMenu();

void PrintMainMenuMessage(const bool isAllItemEnabled);
void PrintSubMenu1Message();

// ****************************************************************************
// ***  Implementation of functions
// ****************************************************************************

int main()
{
	return MainMenu();
}

int MainMenu()
{
	int rowCount = 0;
	int columnCount = 0;
	double matrix[maxRowsSize][maxColumnsSize];
	bool canExit = false;
	while (!canExit)
	{
		PrintMainMenuMessage(0 != rowCount && 0 != columnCount);
		int currentChoise;

		cin >> currentChoise;
		if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
			continue;

		if (0 == rowCount && 0 == columnCount &&
			(currentChoise != kInputMatrixMainMenuChoiseType) && 
			(currentChoise != kClearScreenMainMenuChoiseType) &&
			(currentChoise != kExitProgramMainMenuChoiseType))
		{
			if (kInputMatrixMainMenuChoiseType < currentChoise &&
				currentChoise < kClearScreenMainMenuChoiseType)
			{
				printf(kYouNeedSetupMatrixFirstlyErrorMessage);
			}
			else 
			{
				printf(kThereIsNoCorrespondingOptionErrorMessage);
			}
			continue;
		}

		switch (currentChoise)
		{
			case kInputMatrixMainMenuChoiseType:
			{
				PrintSubMenu1Message();
				cin >> currentChoise;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
					break;

				if ((kInputRandomSubMenu1ChoiseType != currentChoise) &&
					(kInputByKeyboardSubMenu1ChoiseType != currentChoise))
				{
					printf(kEnterCorretChoiseValueErrorMessage);
					break;
				}

				printf(kInputCountOfRowsMessage, maxRowsSize);
				printf(kInputSymbolMessage);
				cin >> rowCount;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretIntValueErrorMessage))
					break;
				if (rowCount <= 0 || rowCount > maxRowsSize)
				{
					printf(kIncorrectRangeValueErrorMessage, maxRowsSize);
					break;
				}

				printf(kInputCountOfColumnsMessage, maxColumnsSize);
				printf(kInputSymbolMessage);
				cin >> columnCount;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretIntValueErrorMessage))
					break;
				if (columnCount <= 0 || columnCount > maxColumnsSize)
				{
					printf(kIncorrectRangeValueErrorMessage, maxColumnsSize);
					break;
				}

				switch (currentChoise)
				{
					case kInputRandomSubMenu1ChoiseType:
					{
						SetupMatrixRandomly(matrix, rowCount, columnCount);
						break;
					}
					case kInputByKeyboardSubMenu1ChoiseType:
					{
						InputMatrixByKeyboard(matrix, rowCount, columnCount);
						break;
					}
					default:
					{
						printf(kEnterCorretChoiseValueErrorMessage);
						break;
					}
				}
				break;
			}
			case kPrintMatrixMainMenuChoiseType:
			{
				printf("\n");
				PrintMatrix(matrix, rowCount, columnCount);
				break;
			}
			case kSetupMatrixToZeroMainMenuChoiseType:
			{
				SetupMatrixToZero(matrix, rowCount, columnCount);
				break;
			}
			case kMakeSortForMatrixMainMenuChoiseType:
			{
				printf(kHowMakeSortOfMatrixMessage);
				printf(kInputSymbolMessage);

				int isAscendingSort;
				cin >> isAscendingSort;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretIntValueErrorMessage))
					break;

				MakeSortForMatrix(matrix, rowCount, columnCount, isAscendingSort == 1);
				break;
			}
			case kShiftMatrixMainMenuChoiseType:
			{
				printf(kInputShiftCountMessage);
				printf(kInputSymbolMessage);

				int shiftValue;
				cin >> shiftValue;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretIntValueErrorMessage))
					break;

				ShiftMatrix(matrix, rowCount, columnCount, shiftValue);
				break;
			}
			case kClearScreenMainMenuChoiseType:
			{
				system("cls");
				break;
			}
			case kExitProgramMainMenuChoiseType:
			{
				printf(kConfirmExitMessage);
				printf(kInputSymbolMessage);
				char answerString[80];
				gets_s(answerString);

				int length = strlen(answerString);
				for (int i = 0; i < length; i++)
					answerString[i] = tolower(answerString[i]);
				
				if (strcmp(answerString, "y") == 0 || strcmp(answerString, "yes") == 0)
					canExit = true;
				break;
			}
			default:
			{
				printf(kThereIsNoCorrespondingOptionErrorMessage);
				break;
			}
		}
	}

	return 0;
}

void PrintMainMenuMessage(const bool isAllItemEnabled)
{
	printf(kChoiseActionMessage);
	printf(kInputMatrixMessage);

	if (!isAllItemEnabled)
		printf(kDisableStateSymbolMessage);
	printf(kPrintMatrixMessage);

	if (!isAllItemEnabled)
		printf(kDisableStateSymbolMessage);
	printf(kSetupMatrixToZeroMessage);

	if (!isAllItemEnabled)
		printf(kDisableStateSymbolMessage);
	printf(kMakeSortForMatrixMessage);

	if (!isAllItemEnabled)
		printf(kDisableStateSymbolMessage);
	printf(kShiftMatrixMessage);

	printf(kClearScreenMessage);
	printf(kExitProgramMessage);
	printf(kInputSymbolMessage);
}

void PrintSubMenu1Message()
{
	printf(kSubMenu1Message);
	printf(kInputSymbolMessage);
}