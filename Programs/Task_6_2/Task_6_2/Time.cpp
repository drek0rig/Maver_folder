#include "Time.h"

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

const int kMinTimeValue = 0;
const int kMaxTimeValue = 1439;
const int kMaxReturnStringValueLenth = 20;

static const char kMinutesPostfixMessage[]			= " minute(s).";
static const char kDoubleDotMessage[]				= ":";
static const char kAnteMeridiemTimePostfix[]		= " a.m.";
static const char kPostMeridiemTimePostfix[]		= " p.m.";
static const char kMidnightTwentyFourHour[]			= "00";

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Time::Time()
{
#ifdef LOG_PRINT
	printf("Time Default constructor called!");
#endif
	_time = new int;
	_timeType = new TimeMeasurementType;
	*_time = 0;
	*_timeType = DefaultHourType;
	_operationExist = true;
}

Time::Time(int time, TimeMeasurementType timeType, bool operationExist)
{
#ifdef LOG_PRINT
	printf("Time Constructor called!");
#endif
	_time = new int;
	_timeType = new TimeMeasurementType;
	*_time = time;
	*_timeType = timeType;
	_operationExist = operationExist;
}

Time::Time(const Time& rhs)
{
#ifdef LOG_PRINT
	printf("Time Copy constructor called!");
#endif
	_time = new int;
	_timeType = new TimeMeasurementType;
	*_time = rhs.getTime();
	*_timeType = rhs.getTimeType();
	_operationExist = true;
}

Time::~Time()
{
#ifdef LOG_PRINT
	printf("Time Destructor called!");
#endif
	delete _time;
	_time = 0;
	delete _timeType;
	_timeType = 0;
}

Time& Time::operator=(const Time& rhs)
{
	if (this == &rhs)
		return *this;
	*_time = rhs.getTime();
	*_timeType = rhs.getTimeType();
	_operationExist = rhs._operationExist;
	return *this;
}

void Time::setTime(const int time)
{
	*_time = time;
}

int Time::getTime() const
{
	return *_time;
}

int Time::getTimeMinutes() const
{
	int localTime = 0;

	switch (*_timeType)
	{
	case MinutesType:
		{
			localTime = *_time;
			break;
		}
	case TwelfthHourType:
		{
			localTime = *_time % 60;
			if (localTime < 0)
				localTime *= -1;
			break;
		}
	case TwentyFoureHourType:
		{
			localTime = *_time % 60;
			if (localTime < 0)
				localTime *= -1;
			break;
		}
	default:
		{
			localTime = *_time;
			break;
		}
	}

	return localTime;
}

int Time::getTimeHours() const
{	
	int localTime = 0;
		
	switch (*_timeType)
	{
	case MinutesType:
		{
			localTime = *_time / 60;
			break;			
		}
	case TwelfthHourType:
		{
			localTime = *_time / 60;
			if (localTime > 12)
			{
				localTime = localTime - 12;
			}
			else if (localTime == 0)
			{
				localTime = 12;
			}			
			break;
		}
	case TwentyFoureHourType:
		{
			localTime = *_time / 60;
			break;
		}
	default:
		{
			return 0;			
		}
	}

	return localTime;
}

char* Time::getStringValue() const
{
	char* pResult = new char[kMaxReturnStringValueLenth];	
	
	switch (*_timeType)
	{
	case MinutesType:
		{
			char returnString[kMaxReturnStringValueLenth];
			int minutes = getTimeMinutes();

			itoa (minutes, returnString, 10);
			strcat(returnString, kMinutesPostfixMessage);

			strcpy(pResult, returnString);
			break;
		}
	case TwelfthHourType:
		{
			char returnString[kMaxReturnStringValueLenth];
			char tempString[kMaxReturnStringValueLenth];
			int minutes = getTimeMinutes();
			int hour = getTimeHours();

			itoa (hour, returnString, 10);
			itoa (minutes, tempString, 10);

			strcat(returnString, kDoubleDotMessage);
			strcat(returnString, tempString);

			if (getTime() < (kMaxTimeValue + 1) / 2)
				strcat(returnString, kAnteMeridiemTimePostfix);
			else
				strcat(returnString, kPostMeridiemTimePostfix);

			strcpy(pResult, returnString);
			break;
		}
	case TwentyFoureHourType:
		{
			char returnString[kMaxReturnStringValueLenth];					
			char tempString[kMaxReturnStringValueLenth];
			int minutes = getTimeMinutes();
			int hour = getTimeHours();
			
			itoa (minutes, tempString, 10);

			if (hour != 0)
				itoa (hour, returnString, 10);
			else
				strcpy(returnString, kMidnightTwentyFourHour);

			strcat(returnString, kDoubleDotMessage);
			strcat(returnString, tempString);

			strcpy(pResult, returnString);			
			break;
		}
	default:
		{			
			break;
		}
	}

	return pResult;
}

void Time::setTimeType(const TimeMeasurementType timeType)
{
	*_timeType = timeType;
}

TimeMeasurementType Time::getTimeType() const
{
	return *_timeType;
}

bool Time::isAddTimeLastOperation() const
{
	return _operationExist;
}

void Time::addTime(const Time* const pAddingTime)
{
	int newTime = *_time + pAddingTime->getTime();
	if (newTime <= kMaxTimeValue)
	{
		*_time = newTime;
	}
	else
	{
		*_time = newTime - kMaxTimeValue - 1;
	}
	_operationExist = true;
}

void Time::minusTime(const Time* const pminusTime)
{
	int newTime = *_time - pminusTime->getTime();
	if (newTime >= kMinTimeValue)
	{
		*_time = newTime;
	}
	else
	{
		*_time = newTime + kMaxTimeValue + 1;
	}
	_operationExist = false;
}

// ****************************************************************************
// ***  Implementation of function
// ****************************************************************************

char* DifferenceBetweenTimes(const Time* const pTimeOne, const Time* const pTimeTwo)
{
	int localTime = pTimeOne->getTime() - pTimeTwo->getTime();
	TimeMeasurementType timeType = pTimeOne->getTimeType();

	Time someTime(localTime, timeType);
	return someTime.getStringValue();
}

char* DifferenceBetweenTimes(const Time& rTimeOne, const Time& rTimeTwo)
{
	int localTime = rTimeOne.getTime() - rTimeTwo.getTime();
	TimeMeasurementType timeType = rTimeOne.getTimeType();

	Time someTime(localTime, timeType);
	return someTime.getStringValue();
}