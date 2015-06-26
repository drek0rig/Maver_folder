#include "Nozdormu.h"
#include "Time.h"

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

static const char kInputSymbolMessage[]					= ">> ";

// Started messages for operation and creation objects
static const char kGreetingsMessage[]					= "Hello, you are inside program which work with time.\n";
static const char kChooseEntranceValueTypeMessage[]		= "Choose what values will we use for next operation:\n"
														 "1 - Default values.\n"
														 "2 - Enter values from the keaboard.\n";

static const char kChooseTimeMeasurementTypeMessage[]	= "\nChoose time measurement format:\n"
														  "1 - Minutes format (0-1439 minutes day).\n"
														  "2 - 12-hour format (1-12 hour day).\n"
														  "3 - 24-hour format (00:00-23:59 day).\n";

static const char kEnterTimeMessage[]					= "\nEnter time value (in minutes) ";
	
//Printing message
static const char kEnteredValuesCheckMessage[]			= "\nEntered value check.\n";

static const char kaddTimeLastOperationStatusMessage[]	= "\nAdd time operation status is: ";
static const char kTrueSatusMessage[]					= "true.\n";
static const char kFalseSatusMessage[]					= "false.\n";

//Printing after manipulation
static const char kAddingFirstAndSecondCheckMessage[]	= "\nCheck after adding first and second time.\n";
static const char kMinusSecondFromFirstCheckMessage[]	= "\nCheck after second minus from first.\n";
static const char kDifferenceFunctionCheckMessage[]		= "\nCheck after 'DifferenceBetweenTimes' function.\n";

//Error messages
static const char kEnterCorrectValueMessage[]			= "\nPlease, enter correct value.\n\n";
static const char kEnterValueInRangeMessage[]			= "\nEnter value in range 1-%d.\n\n";
static const char kEnterValueInCertaineRangeMessage[]	= "\nEnter value in range %d-%d.\n\n";

typedef enum
{
	kDefaultValueChoiseType			= 1,
	kKeaboardValueChoiseType		= 2,
	kMaxEntranceValueTypeChoiseType	= kKeaboardValueChoiseType
} EntranceValueTypeChoiseType;

// ****************************************************************************
// ***  Interface of local fuctions
// ****************************************************************************

bool MakeCheckForNumberInputFromCin();
Time* CreateTimeObject(EntranceValueTypeChoiseType valueType);
void TimePrint(const Time* const pTheTime);
void TimeStatusPrint(const Time* const pTheTime);

// ****************************************************************************
// ***  Implementation of functions
// ****************************************************************************

void Nozdormu()
{
	bool isExit = false;
	EntranceValueTypeChoiseType userEnterValueType;
	while (!isExit)
	{
		printf(kGreetingsMessage);
		printf(kChooseEntranceValueTypeMessage);
		printf(kInputSymbolMessage);
		int currentChoise;

		cin >> currentChoise;

		if (!MakeCheckForNumberInputFromCin())
		{
			printf(kEnterCorrectValueMessage);
			continue;
		}
		else if (currentChoise < 1 || currentChoise > kMaxEntranceValueTypeChoiseType)
		{
			printf(kEnterValueInRangeMessage, kMaxEntranceValueTypeChoiseType);
			continue;
		}

		if (currentChoise == kDefaultValueChoiseType)
		{
			userEnterValueType = kDefaultValueChoiseType;
			break;
		}
		else if (currentChoise == kKeaboardValueChoiseType)
		{
			userEnterValueType = kKeaboardValueChoiseType;
			break;
		}
		isExit = true;
	}
	
	// Three objects creation for operation
	Time* pTimeOne = CreateTimeObject(userEnterValueType);
	Time* pTimeTwo = CreateTimeObject(userEnterValueType);
	Time* pTimeThree = CreateTimeObject(userEnterValueType);

	//Enterd value check
	printf(kEnteredValuesCheckMessage);
	TimePrint(pTimeOne);
	TimeStatusPrint(pTimeOne);
	TimePrint(pTimeTwo);
	TimeStatusPrint(pTimeTwo);
	TimePrint(pTimeThree);
	TimeStatusPrint(pTimeThree);

	//Adding operation example
	pTimeOne->addTime(pTimeTwo);
	
	printf(kAddingFirstAndSecondCheckMessage);
	TimePrint(pTimeOne);
	TimeStatusPrint(pTimeOne);

	//Minus operation example
	pTimeOne->minusTime(pTimeTwo);
	
	printf(kMinusSecondFromFirstCheckMessage);
	TimePrint(pTimeOne);
	TimeStatusPrint(pTimeOne);
		
	//Difference example with pointer parameters	
	printf(kDifferenceFunctionCheckMessage);
	char* deffernceString = DifferenceBetweenTimes(pTimeOne, pTimeTwo);
	printf(deffernceString);
	delete[] deffernceString;

	//Difference example with reference parameters
	printf(kDifferenceFunctionCheckMessage);
	deffernceString = DifferenceBetweenTimes(*pTimeOne, *pTimeTwo);
	printf(deffernceString);
	delete[] deffernceString;

	delete pTimeOne;
	delete pTimeTwo;
	delete pTimeThree;
}

Time* CreateTimeObject(EntranceValueTypeChoiseType valueType)
{
	int localTime = 0;
	TimeMeasurementType timeType;

	switch(valueType)
	{
	case kDefaultValueChoiseType:
		{
			localTime = RandomNumberReturn(kMinTimeValue, kMaxTimeValue);
			timeType = DefaultHourType;
			break;
		}
	case kKeaboardValueChoiseType:
		{
			bool canExit = false;
			while (!canExit)
			{
				printf(kEnterTimeMessage);
				printf(kInputSymbolMessage);
				
				cin >> localTime;
				if (!MakeCheckForNumberInputFromCin())
				{
					printf(kEnterCorrectValueMessage);
					continue;
				}
				else if (localTime < kMinTimeValue || localTime > kMaxTimeValue)
				{
					printf(kEnterValueInCertaineRangeMessage, kMinTimeValue, kMaxTimeValue);
					continue;
				}
				canExit = true;
			}

			canExit = false;
			while(!canExit)
			{
				printf(kChooseTimeMeasurementTypeMessage);
				printf(kInputSymbolMessage);
				int currentChoise;

				cin >> currentChoise;
				if (!MakeCheckForNumberInputFromCin())
				{
					printf(kEnterCorrectValueMessage);
					continue;
				}
				else if (currentChoise < 1 || currentChoise > MaxTimeMeasurementType)
				{
					printf(kEnterValueInRangeMessage, MaxTimeMeasurementType);
					continue;
				}

				timeType = (TimeMeasurementType)currentChoise;
				canExit = true;
			}
			break;
		}
	default:
		{
			printf(kEnterCorrectValueMessage);
			break;
		}
	}

	Time* pResult = new Time(localTime, timeType);
	
	return pResult;
}

void TimePrint(const Time* const pTheTime)
{
	char* tempdelete = pTheTime->getStringValue();
	printf(tempdelete);	
	delete[] tempdelete;
}

void TimeStatusPrint(const Time* const pTheTime)
{
	bool status = pTheTime->isAddTimeLastOperation();

	printf(kaddTimeLastOperationStatusMessage);
	if (status)
	{
		printf(kTrueSatusMessage);
	}
	else
		printf(kFalseSatusMessage);
}

bool MakeCheckForNumberInputFromCin()
{
	bool result = false;
	if (!cin.fail())
	{		
		cin.sync(); 
		result = true; // It's a normal value
	}
	else 
	{		
		cin.clear(); // remove error flags
		cin.ignore();
		cin.sync(); 
	}
	return result;
}