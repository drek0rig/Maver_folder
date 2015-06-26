#include "StartMenu.h"
#include "FunctionsAndClasses.h"
#include "Triangle.h"
#include "Circle.h"
#include <iostream>

using namespace std;

// Constants and types

static const char kInputSymbolMessage[]						= ">>";
static const char kDisableStateSymbolMessage[]				= "--";

// Main menu messages
static const char kChoiseMenuMessage[]						= "Choise Menu item:\n";
static const char kSelectFigureMessage[]					= "1. Select a figure for further work.\n";
static const char kEnterFigureParametersMessage[]			= "2. Enter figure parameters.\n";
static const char kOutputFigureParametersMessage[]			= "3. Output figure parameters.\n";
static const char kFigureShiftMessage[]						= "4. Shift the figure.\n";
static const char kChangeFigureSizeMessage[]				= "5. Change the size of the figure.\n";
static const char kClearScreenMessage[]						= "6. Clear screen.\n";
static const char kExitMenuMessage[]						= "7. Exit.\n";

// First sub menu message
static const char kFirstSubMenuMessage[]					= "Now selecte the figure:\n"
																"1. Rectangel.\n"
																"2. Triangle.\n"
																"3. Circle.\n";
//** Messages for second menu type
//Rectangle
static const char kEnterRectangleXCoordinetMessage[]		= "Enter left down rectangle x coordinate\n";
static const char kEnterRectangleYCoordinetMessage[]		= "Enter left down rectangle Y coordinate\n";
static const char kEnterRectangleWidthMessage[]				= "Enter width of the rectangle\n";
static const char kEnterRectangleHeightMessage[]			= "Enter height of the rectangle\n";
//Triangle
static const char kEnterLeftDownAngleXCoordinetMessage[]	= "Enter X coordinate of triangle left down angle\n";
static const char kEnterLeftDownAngleYCoordinetMessage[]	= "Enter Y coordinate of triangle left down angle\n";
static const char kEnterRightDownAngleXCoordinetMessage[]	= "Enter X coordinate of triangle right down angle\n";
static const char kEnterRightDownAngleYCoordinetMessage[]	= "Enter Y coordinate of triangle right down angle\n";
static const char kEnterUpperAngleXCoordinetMessage[]		= "Enter X coordinate of triangle upper angle\n";
static const char kEnterUpperAngleYCoordinetMessage[]		= "Enter Y coordinate of triangle upper angle\n";
//Circle
static const char kEnterCenterXCoordinetMessage[]			= "Enter X coordinate of the center of a circle\n";
static const char kEnterCenterYCoordinetMessage[]			= "Enter Y coordinate of the center of a circle\n";
static const char kEnterCircleRadiusMessage[]				= "Enter radius of the circle\n";

//** Messages for third menu type
//Rectangle
static const char kRectangleXOutputMessage[]				= "X coordinate of rectangle left down angle is: %d\n";
static const char kRectangleYOutputMessage[]				= "Y coordinate of rectangle left down angle is: %d\n";
static const char kRectangleWidthOutputMessage[]			= "Width of the rectangle is: %d\n";
static const char kRectangleHeightOutputMessage[]			= "Height of the rectangle is: %d\n";
//Triangle
static const char kLeftDownAngleXOutputMessage[]			= "X coordinate of triangle left down angle is: %d\n";
static const char kLeftDownAngleYOutputMessage[]			= "Y coordinate of triangle left down angle is: %d\n";
static const char kRightDownAngleXOutputMessage[]			= "X coordinate of triangle right down angle is: %d\n";
static const char kRightDownAngleYOutputMessage[]			= "Y coordinate of triangle right down angle is: %d\n";
static const char kUpperAngleXOutputMessage[]				= "X coordinate of triangle upper angle is: %d\n";
static const char kUpperAngleYOutputMessage[]				= "Y coordinate of triangle upper angle is: %d\n";
//Circle
static const char kCenterCoordinateOutputMessage[]			= "X Y coordinate of the center of a circle is: %d %d\n";
static const char kCircleRadiusOutputMessage[]				= "Radius of the circle is: %d\n";

//** Messages for fourth menu type
static const char kShiftingDoneMessage[]					= "Shifting is done!\n";
// Messages for submenu 4
static const char kFourthMenuTypeSubmenuMessage[]			= "Select direction of shifting:\n"
															  "1. Left.\n"
															  "2. Right.\n"
															  "3. Up.\n"
															  "4. Down.\n";

//** Messages for fifth menu type
static const char kSizeChangeMessage[]						= "Size is change!\n";
// Messages for submenu 5
static const char kFifthMenuTypeSubmenuMessage[]			= "Select resizing:\n"
															  "1. Decrease.\n"
															  "2. Increase.\n";
// Exit confirmation message
static const char kExitConfifmationMessage[]				= "Are you sure?\n";

// Error messages
static const char kEnterCorrectChoiseValueErrorMessage[]	= "Please, enter correct choise value.\n";
static const char kYouNeedSelectFigureFirstlyErrorMessage[]	= "You need select a figure before use this option.\n";
static const char kNoCorrespondingOptionErrorMessage[]		= "There is no corresponding option for you choise.\n";
static const char kEnterCorrectValueErrorMessage[]			= "Please, enter correct value.\n";

typedef enum
{
	kSelectFigureChoiseType				= 1,
	kEnterFigureParametersChoiseType	= 2,
	kOutputFigureParametersChoiseType	= 3,
	kFigureShiftChoiseType				= 4,
	kChangeFigureSizeChoiseType			= 5,
	kClearScreenChoiseType				= 6,
	kExitChoiseType						= 7
} MaineMenuChoiseType;

typedef enum
{
	kRectangleChoiseType				= 1,
	kTriangleChoiseType					= 2,
	kCircleChoiseType					= 3
} FirstSubMenuFigureChoiseType;

typedef enum
{
	kLeftChoiseType						= 1,
	kRightChoiseType					= 2,
	kUpChoiseType						= 3,
	kDownChoiseType						= 4,
} FourthMenuSubmenuChoiseType;

typedef enum
{
	kDecreaseChoiseType					= 1,
	kIncreaseChoiseType					= 2,
} FifthMenuSubmenuChoiseType;

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[]);

int StartMenu()
{
	bool exit = false;
	int figureChoise = 0;

	Rectangle NewRectangle;
	Triangle NewTriangle;
	Circle NewCircle;

	while(!exit)
	{
		PrintMainMenu(figureChoise);
		int currentChoise;

		cin >> currentChoise;
		if (!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
			continue;

		if (!figureChoise && (currentChoise != kSelectFigureChoiseType) &&
			(currentChoise != kClearScreenChoiseType) &&
			(currentChoise != kExitChoiseType))
		{
			if (currentChoise > kSelectFigureChoiseType &&
				currentChoise < kClearScreenChoiseType)
			{
				printf(kYouNeedSelectFigureFirstlyErrorMessage);
				continue;
			}
			else
			{
				printf(kNoCorrespondingOptionErrorMessage);
				continue;
			}
		}

		switch (currentChoise)
		{
		 case kSelectFigureChoiseType:
			{
				PrintFirstSubMenu();
				cin >> currentChoise;

				if (!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

				if (currentChoise != kRectangleChoiseType &&
					currentChoise != kTriangleChoiseType &&
					currentChoise != kCircleChoiseType)
				{
					printf(kEnterCorrectChoiseValueErrorMessage);
					break;
				}

				switch (currentChoise)
				{
				 case kRectangleChoiseType:
					 {
						 figureChoise = kRectangleChoiseType;
						 break;
					 }
				 case kTriangleChoiseType:
					 {
						 figureChoise = kTriangleChoiseType;
						 break;
					 }
				 case kCircleChoiseType:
					 {						 
						 figureChoise = kCircleChoiseType;
						 break;
					 }
				 default:
					 {
						 printf(kNoCorrespondingOptionErrorMessage);
						 break;
					 }
				}
				break;
			}
		 case kEnterFigureParametersChoiseType:
			 {
				 if (figureChoise == kRectangleChoiseType)
				 {
					 printf(kEnterRectangleXCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int rectX;					 
					 cin >> rectX;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewRectangle.SetLeftDownAngleX(rectX);
					 
					 printf(kEnterRectangleYCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int rectY;
					 cin >> rectY;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewRectangle.SetLeftDownAngleY(rectY);

					 printf(kEnterRectangleWidthMessage);
					 printf(kInputSymbolMessage);
					 int rectWidth;
					 cin >> rectWidth;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewRectangle.SetWidth(rectWidth);

					 printf(kEnterRectangleHeightMessage);
					 printf(kInputSymbolMessage);
					 int rectHeight;
					 cin >> rectHeight;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewRectangle.SetHeight(rectHeight);					 
				 }
				 else if (figureChoise == kTriangleChoiseType)
				 {
					 printf(kEnterLeftDownAngleXCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int leftDownAngleX;
					 cin >> leftDownAngleX;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetFirstPointX(leftDownAngleX);

					 printf(kEnterLeftDownAngleYCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int leftDownAngleY;
					 cin >> leftDownAngleY;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetFirstPointY(leftDownAngleY);

					 printf(kEnterRightDownAngleXCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int rightDownAngleX;
					 cin >> rightDownAngleX;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetSecondPointX(rightDownAngleX);

					 printf(kEnterRightDownAngleYCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int rightDownAngleY;
					 cin >> rightDownAngleY;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetSecondPointY(rightDownAngleY);

					 printf(kEnterUpperAngleXCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int upperAngleX;
					 cin >> upperAngleX;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetThirdPointX(upperAngleX);

					 printf(kEnterUpperAngleYCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int upperAngleY;
					 cin >> upperAngleY;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewTriangle.SetThirdPointY(upperAngleY);					 
				 }
				 else if (figureChoise == kCircleChoiseType)
				 {
					 printf(kEnterCenterXCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int circleCenterX;
					 cin >> circleCenterX;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewCircle.SetCenterX(circleCenterX);

					 printf(kEnterCenterYCoordinetMessage);
					 printf(kInputSymbolMessage);
					 int circleCenterY;
					 cin >> circleCenterY;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewCircle.SetCenterY(circleCenterY);

					 printf(kEnterCircleRadiusMessage);
					 printf(kInputSymbolMessage);
					 int circleRadius;
					 cin >> circleRadius;
					 if (!MakeCheckForNumberInputFromCin(kEnterCorrectValueErrorMessage))
					 break;
					 NewCircle.SetRadius(circleRadius);					 
				 }
				 break;
				 }
			case kOutputFigureParametersChoiseType:
				{
					if (figureChoise == kRectangleChoiseType)
					{
						printf(kRectangleXOutputMessage, NewRectangle.GetLeftDownAngleX());
						printf(kRectangleYOutputMessage, NewRectangle.GetLeftDownAngleY());
						printf(kRectangleWidthOutputMessage, NewRectangle.GetWidth());
						printf(kRectangleHeightOutputMessage, NewRectangle.GetHeight());
					}
					else if (figureChoise == kTriangleChoiseType)
					{
						printf(kLeftDownAngleXOutputMessage, NewTriangle.GetFirstPointX());
						printf(kLeftDownAngleYOutputMessage, NewTriangle.GetFirstPointY());
						printf(kRightDownAngleXOutputMessage, NewTriangle.GetSecondPointX());
						printf(kRightDownAngleYOutputMessage, NewTriangle.GetSecondPointY());
						printf(kUpperAngleXOutputMessage, NewTriangle.GetThirdPointX());
						printf(kUpperAngleYOutputMessage, NewTriangle.GetThirdPointY());
					}
					else if (figureChoise == kCircleChoiseType)
					{
						printf(kCenterCoordinateOutputMessage, NewCircle.GetCenterX(), NewCircle.GetCenterY());
						printf(kCircleRadiusOutputMessage, NewCircle.GetRadius());
					}
					break;
				}
			case kFigureShiftChoiseType:
				{
					PrintFourthMenuSubmenu();
					cin >> currentChoise;

					if (!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

					if (currentChoise != kLeftChoiseType &&
						currentChoise != kRightChoiseType &&
						currentChoise != kUpChoiseType &&
						currentChoise != kDownChoiseType)
					{
						printf(kEnterCorrectChoiseValueErrorMessage);
						break;
					}

					switch (currentChoise)
					{
					 case kLeftChoiseType:
						 {
							 if (figureChoise == kRectangleChoiseType)
							 {
								 NewRectangle.RectangleShifting(kLeftChoiseType);
							 }
							 else if (figureChoise == kTriangleChoiseType)
							 {
								 NewTriangle.TriangleShifting(kLeftChoiseType);
							 }
							 else if (figureChoise == kCircleChoiseType)
							 {
								 NewCircle.CircleShifting(kLeftChoiseType);
							 }
							 break;
						 }
					 case kRightChoiseType:
						 {
							 if (figureChoise == kRectangleChoiseType)
							 {
								 NewRectangle.RectangleShifting(kRightChoiseType);
							 }
							 else if (figureChoise == kTriangleChoiseType)
							 {
								 NewTriangle.TriangleShifting(kRightChoiseType);
							 }
							 else if (figureChoise == kCircleChoiseType)
							 {
								 NewCircle.CircleShifting(kRightChoiseType);
							 }
							 break;
						 }
					 case kUpChoiseType:
						 {
							 if (figureChoise == kRectangleChoiseType)
							 {
								 NewRectangle.RectangleShifting(kUpChoiseType);
							 }
							 else if (figureChoise == kTriangleChoiseType)
							 {
								 NewTriangle.TriangleShifting(kUpChoiseType);
							 }
							 else if (figureChoise == kCircleChoiseType)
							 {
								 NewCircle.CircleShifting(kUpChoiseType);
							 }
							 break;
						 }
					 case kDownChoiseType:
						 {
							 if (figureChoise == kRectangleChoiseType)
							 {
								 NewRectangle.RectangleShifting(kDownChoiseType);
							 }
							 else if (figureChoise == kTriangleChoiseType)
							 {
								 NewTriangle.TriangleShifting(kDownChoiseType);
							 }
							 else if (figureChoise == kCircleChoiseType)
							 {
								 NewCircle.CircleShifting(kDownChoiseType);
							 }
							 break;
						 }
					 default:
						 {
							 printf(kNoCorrespondingOptionErrorMessage);
							 break;
						 }
					}
					printf(kShiftingDoneMessage);
					break;
				}
			case kChangeFigureSizeChoiseType:
				{
					PrintFifthMenuSubmenu();
					
					cin >> currentChoise;
					if (!MakeCheckForNumberInputFromCin(kEnterCorrectChoiseValueErrorMessage))
					break;

					if (currentChoise != kDecreaseChoiseType &&
						currentChoise != kIncreaseChoiseType)
					{
						printf(kEnterCorrectChoiseValueErrorMessage);
						break;
					}

					if (figureChoise == kRectangleChoiseType)
					{
						if (currentChoise == kDecreaseChoiseType)
						{
							NewRectangle.WidthDecrease();
							NewRectangle.HeightDecrease();
						}
						else
						{
							NewRectangle.WidthIncrease();
							NewRectangle.HeightIncrease();
						}
					}
					else if (figureChoise == kTriangleChoiseType)
					{
						if (currentChoise == kDecreaseChoiseType)
						{
							NewTriangle.TriangleDecrease();
						}
						else
						{
							NewTriangle.TriangleIncrease();
						}
					}
					else if (figureChoise == kCircleChoiseType)
					{
						if (currentChoise == kDecreaseChoiseType)
						{
							NewCircle.CircleDecrease();
						}
						else
						{
							NewCircle.CircleIncrease();
						}
					}
					break; 
				}
			case kClearScreenChoiseType:
				{
					system("cls");
					break;
				}
			case kExitChoiseType:
				{
					printf(kExitConfifmationMessage);
					printf(kInputSymbolMessage);
					char answerString[20];
					gets_s(answerString);

					int lenght = strlen(answerString);
					for (int i = 0; i < lenght; i++)
						answerString[i] = tolower(answerString[i]);

					if (strcmp(answerString, "y") == 0 || strcmp(answerString, "yes") == 0)
						exit = true;
					break;
				}
			default:
				{
					printf(kNoCorrespondingOptionErrorMessage);
					break;
				}
			 
		}
	}

	return 0;
}

void PrintMainMenu(const bool isAllInitialDataDetermaine)
{
	printf(kChoiseMenuMessage);
	printf(kSelectFigureMessage);

	if (!isAllInitialDataDetermaine)
		printf(kDisableStateSymbolMessage);
	printf(kEnterFigureParametersMessage);

	if (!isAllInitialDataDetermaine)
		printf(kDisableStateSymbolMessage);
	printf(kOutputFigureParametersMessage);

	if (!isAllInitialDataDetermaine)
		printf(kDisableStateSymbolMessage);
	printf(kFigureShiftMessage);

	if (!isAllInitialDataDetermaine)
		printf(kDisableStateSymbolMessage);
	printf(kChangeFigureSizeMessage);

	printf(kClearScreenMessage);
	printf(kExitMenuMessage);
	printf(kInputSymbolMessage);
}

void PrintFirstSubMenu()
{
	printf(kFirstSubMenuMessage);
	printf(kInputSymbolMessage);
}

void PrintFourthMenuSubmenu()
{
	printf(kFourthMenuTypeSubmenuMessage);
	printf(kInputSymbolMessage);
}

void PrintFifthMenuSubmenu()
{
	printf(kFifthMenuTypeSubmenuMessage);
	printf(kInputSymbolMessage);
}

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