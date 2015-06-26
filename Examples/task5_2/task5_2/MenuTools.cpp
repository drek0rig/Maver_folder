#include "MenuTools.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>

using namespace std;

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kInputSymbolMessage[]				= ">> ";
static const char kDisableStateSymbolMessage[]		= "-- ";

static const char kInputXValueMessage[]				= "Input X value: ";
static const char kInputYValueMessage[]				= "Input Y value: ";

static const char kInputWidthValueMessage[]			= "Input width value: ";
static const char kInputHeightValueMessage[]		= "Input height value: ";

// Messages of main menu
static const char kChoiseActionMessage[]			= "\nChoise action:\n";
static const char kChooseFigureTypeMessage[]		= "1. Choose figure type;\n";
static const char kInputFigureAttributesMessage[]	= "2. Input figure attributes;\n";
static const char kPrintFigureAttributesMessage[]	= "3. Print figure attributes;\n";
static const char kMakeMoveOfFigureMessage[]		= "4. Make move of figure;\n";
static const char kMakeResizeOfFigureMessage[]		= "5. Make resize of figure;\n";
static const char kClearScreenMessage[]				= "6. Clear screen;\n";
static const char kExitProgramMessage[]				= "7. Exit;\n";

// Messages of sub menu 1
static const char kSubMenu1Message[]				= "\nWhat figure do you want?\n"
													  "1. triangle;\n"
													  "2. circle;\n"
													  "3. rectangle;\n";

// Messages of sub menu 2
static const char kInputTriangleAttributeMessage[]	= "\nInputing triangle attributes:\n";
static const char kInputTriangleTopPointMessage[]	= "Input top point value\n";
static const char kInputTriangleLeftPointMessage[]	= "Input bottom left point value\n";
static const char kInputTriangleRightPointMessage[]	= "Input bottom right point value\n";

static const char kInputCircleAttributeMessage[]	= "\nInputing circle attributes:\n";
static const char kInputCircleCenterPointMessage[]	= "Input center point value\n";
static const char kInputCircleRadiusMessage[]		= "Input radius value: ";

static const char kInputRectangleAttributeMessage[]	= "\nInputing rectangle attributes:\n";
static const char kInputRectangleLeftPointMessage[]	= "Input bottom left point value\n";
static const char kInputRectangleSizeMessage[]			= "Input size value: \n";

// Messages of sub menu 4
static const char kSubMenu4Message[]				= "\nIn what direction you want move the figure?\n"
													  "1. up direction;\n"
													  "2. down direction;\n"
													  "3. left direction;\n"
													  "4. right direction;\n";

// Messages of sub menu 5
static const char kSubMenu5Message[]				= "\nHow to scale your figure?\n"
													  "1. increase;\n"
													  "2. decrease;\n";

// Messages of sub menu 7
static const char kConfirmExitMessage[]				= "Are you sure?\n";

// Error messages
static const char kYouNeedChooseFigureFirstlyErrorMessage[]		= "You must first choose figure type from option one, before use this option!\n";
static const char kThereIsNoCorrespondingOptionErrorMessage[]	= "There is no corresponding option for you choise!\n";
static const char kEnterCorretChoiseValueErrorMessage[]			= "Please enter corret choise value.\n";
static const char kEnterCorretNumberValueErrorMessage[]			= "Please enter corret number value.\n";

static const char kEnterNonnegativeRadiusValueErrorMessage[]	= "Please enter radius value more than zero.\n";

typedef enum
{
	kTriangleFigureType		= 1,
	kCircleFigureType		= 2,
	kRectangleFigureType		= 3,
	kUndefinedFigureType	= 0
} FigureType;

typedef enum
{
	kChooseFigureMainMenuChoiseType			= 1,
	kInputFigureAttrMainMenuChoiseType		= 2,
	kPrintFigureAttrMainMenuChoiseType		= 3,
	kMoveFigureMainMenuChoiseType			= 4,
	kResizeFigureMainMenuChoiseType			= 5,
	kClearScreenMainMenuChoiseType			= 6,
	kExitProgramMainMenuChoiseType			= 7
} MainMenuChoiseType;

typedef enum
{
	kMainMenuMessageType					= 1,
	kChooseFigureSubMenuMessageType			= 2,
	kMoveFigureSubMenuMessageType			= 3,
	kResizeFigureSubMenuMessageType			= 4
} MenuMessageType;

// ****************************************************************************
// ***  Interface of private functions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[]);
void PrintMenuMessage(const MenuMessageType menuMessageType, const bool isAllItemEnabled = true);

Triangle DefaultTriangleFigure();
Circle DefaultCircleFigure();
Rectangle DefaultRectangleFigure();

Triangle InputTriangleFigureAttribute();
Circle InputCircleFigureAttribute();
Rectangle InputRectangleFigureAttribute();

Point InputPointValue();
Size InputSizeValue();

// ****************************************************************************
// ***  Implementation of public functions
// ****************************************************************************

int RunMainMenu()
{
	FigureType currentFigureType = kUndefinedFigureType;
	Triangle triangleFigure;
	Circle circleFigure;
	Rectangle rectangleFigure;

	bool canExit = false;
	while (!canExit)
	{
		PrintMenuMessage(kMainMenuMessageType, kUndefinedFigureType != currentFigureType);
		int currentChoise;

		cin >> currentChoise;
		if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
			continue;

		if (kUndefinedFigureType == currentFigureType &&
			(currentChoise != kChooseFigureMainMenuChoiseType) && 
			(currentChoise != kClearScreenMainMenuChoiseType) &&
			(currentChoise != kExitProgramMainMenuChoiseType))
		{
			if (kChooseFigureMainMenuChoiseType < currentChoise &&
				currentChoise < kClearScreenMainMenuChoiseType)
			{
				printf(kYouNeedChooseFigureFirstlyErrorMessage);
			}
			else 
			{
				printf(kThereIsNoCorrespondingOptionErrorMessage);
			}
			continue;
		}

		switch (currentChoise)
		{
			case kChooseFigureMainMenuChoiseType:
			{
				PrintMenuMessage(kChooseFigureSubMenuMessageType);
				cin >> currentChoise;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
					break;

				if ((kTriangleFigureType > currentChoise) ||
					(kRectangleFigureType < currentChoise))
				{
					printf(kEnterCorretChoiseValueErrorMessage);
					break;
				}

				currentFigureType = (FigureType)currentChoise;
				switch (currentFigureType)
				{
					case kTriangleFigureType:
					{
						triangleFigure = DefaultTriangleFigure();
						break;
					}
					case kCircleFigureType:
					{
						circleFigure = DefaultCircleFigure();
						break;
					}
					case kRectangleFigureType:
					{
						rectangleFigure = DefaultRectangleFigure();
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			case kInputFigureAttrMainMenuChoiseType:
			{
				switch (currentFigureType)
				{
					case kTriangleFigureType:
					{
						triangleFigure = InputTriangleFigureAttribute();
						break;
					}
					case kCircleFigureType:
					{
						circleFigure = InputCircleFigureAttribute();
						break;
					}
					case kRectangleFigureType:
					{
						rectangleFigure = InputRectangleFigureAttribute();
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			case kPrintFigureAttrMainMenuChoiseType:
			{
				switch (currentFigureType)
				{
					case kTriangleFigureType:
					{
						triangleFigure.printContent();
						break;
					}
					case kCircleFigureType:
					{
						circleFigure.printContent();
						break;
					}
					case kRectangleFigureType:
					{
						rectangleFigure.printContent();
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			case kMoveFigureMainMenuChoiseType:
			{
				PrintMenuMessage(kMoveFigureSubMenuMessageType);
				cin >> currentChoise;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
					break;

				if ((kUpDirectionMove > currentChoise) ||
					(kLeftDirectionMove < currentChoise))
				{
					printf(kEnterCorretChoiseValueErrorMessage);
					break;
				}

				DirectionMoveType directionMoveType = (DirectionMoveType)currentChoise;
				switch (currentFigureType)
				{
					case kTriangleFigureType:
					{
						triangleFigure.makeMove(directionMoveType);
						break;
					}
					case kCircleFigureType:
					{
						circleFigure.makeMove(directionMoveType);
						break;
					}
					case kRectangleFigureType:
					{
						rectangleFigure.makeMove(directionMoveType);
						break;
					}
					default:
					{
						break;
					}
				}
				break;
			}
			case kResizeFigureMainMenuChoiseType:
			{
				PrintMenuMessage(kResizeFigureSubMenuMessageType);
				cin >> currentChoise;
				if (!MakeCheckForNumberInputFromCin(kEnterCorretChoiseValueErrorMessage))
					break;

				if (1 != currentChoise && 2 != currentChoise)
				{
					printf(kEnterCorretChoiseValueErrorMessage);
					break;
				}

				bool isIncreaseScale = 1 == currentChoise;
				switch (currentFigureType)
				{
					case kTriangleFigureType:
					{
						triangleFigure.makeResize(isIncreaseScale);
						break;
					}
					case kCircleFigureType:
					{
						circleFigure.makeResize(isIncreaseScale);
						break;
					}
					case kRectangleFigureType:
					{
						rectangleFigure.makeResize(isIncreaseScale);
						break;
					}
					default:
					{
						break;
					}
				}
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

void PrintMenuMessage(const MenuMessageType menuMessageType, const bool isAllItemEnabled)
{
	switch (menuMessageType)
	{
		case kMainMenuMessageType:
		{
			printf(kChoiseActionMessage);
			printf(kChooseFigureTypeMessage);

			if (!isAllItemEnabled)
				printf(kDisableStateSymbolMessage);
			printf(kInputFigureAttributesMessage);

			if (!isAllItemEnabled)
				printf(kDisableStateSymbolMessage);
			printf(kPrintFigureAttributesMessage);

			if (!isAllItemEnabled)
				printf(kDisableStateSymbolMessage);
			printf(kMakeMoveOfFigureMessage);

			if (!isAllItemEnabled)
				printf(kDisableStateSymbolMessage);
			printf(kMakeResizeOfFigureMessage);

			printf(kClearScreenMessage);
			printf(kExitProgramMessage);
			printf(kInputSymbolMessage);
			break;
		}
		case kChooseFigureSubMenuMessageType:
		{
			printf(kSubMenu1Message);
			printf(kInputSymbolMessage);
			break;
		}
		case kMoveFigureSubMenuMessageType:
		{
			printf(kSubMenu4Message);
			printf(kInputSymbolMessage);
			break;
		}
		case kResizeFigureSubMenuMessageType:
		{
			printf(kSubMenu5Message);
			printf(kInputSymbolMessage);
			break;
		}
		default:
		{
			break;
		}
	}
}

Triangle DefaultTriangleFigure()
{
	Triangle result;
	result.setTopPoint(Point(0.0, 3.0));
	result.setBottomLeftPoint(Point(-1.0, 0.0));
	result.setBottomRightPoint(Point(5.0, 0.0));
	return result;
}

Circle DefaultCircleFigure()
{
	Circle result;
	result.setCenterPoint(Point(0.0, 0.0));
	result.setRadius(3.0);
	return result;
}

Rectangle DefaultRectangleFigure()
{
	Rectangle result;
	result.setBottomLeftPoint(Point(0.0, 0.0));
	result.setSize(Size(3.0, 2.0));
	return result;
}

Triangle InputTriangleFigureAttribute()
{
	Triangle result;
	printf(kInputTriangleAttributeMessage);

	printf(kInputTriangleLeftPointMessage);
	result.setBottomLeftPoint(InputPointValue());

	printf(kInputTriangleTopPointMessage);
	result.setTopPoint(InputPointValue());

	printf(kInputTriangleRightPointMessage);
	result.setBottomRightPoint(InputPointValue());
	return result;
}

Circle InputCircleFigureAttribute()
{
	Circle result;
	printf(kInputCircleAttributeMessage);

	printf(kInputCircleCenterPointMessage);
	result.setCenterPoint(InputPointValue());

	double radius = 0;
	while (true)
	{
		printf(kInputCircleRadiusMessage);
		
		cin >> radius;
		if (!MakeCheckForNumberInputFromCin(kEnterCorretNumberValueErrorMessage))
			continue;

		if (radius < 0.000001)
		{
			printf(kEnterNonnegativeRadiusValueErrorMessage);
			continue;
		}

		break;
	}
	result.setRadius(radius);

	return result;
}

Rectangle InputRectangleFigureAttribute()
{
	Rectangle result;
	printf(kInputRectangleAttributeMessage);

	printf(kInputRectangleLeftPointMessage);
	result.setBottomLeftPoint(InputPointValue());

	printf(kInputRectangleSizeMessage);
	result.setSize(InputSizeValue());

	return result;
}

Point InputPointValue()
{
	Point result;
	while (true)
	{
		printf(kInputXValueMessage);
		cin >> result.x;

		if (!MakeCheckForNumberInputFromCin(kEnterCorretNumberValueErrorMessage))
			continue;

		break;
	}

	while (true)
	{
		printf(kInputYValueMessage);
		cin >> result.y;

		if (!MakeCheckForNumberInputFromCin(kEnterCorretNumberValueErrorMessage))
			continue;

		break;
	}
	return result;
}

Size InputSizeValue()
{
	Size result;
	while (true)
	{
		printf(kInputWidthValueMessage);
		cin >> result.width;

		if (!MakeCheckForNumberInputFromCin(kEnterCorretNumberValueErrorMessage))
			continue;

		break;
	}

	while (true)
	{
		printf(kInputHeightValueMessage);
		cin >> result.height;

		if (!MakeCheckForNumberInputFromCin(kEnterCorretNumberValueErrorMessage))
			continue;

		break;
	}
	return result;
}
