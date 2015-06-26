#include <string.h>
#include "Time.h"

#ifdef SHOW_DEBUG_MESSAGES
#include <stdio.h>
#endif

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

const HoursCountType kMaxHoursInAMPMMode	= 12; 
const HoursCountType kMaxHoursInDay			= 24; 
const MinutsCountType kMaxMinutsInHour		= 60; 
const MinutsCountType kMaxMinutsInDay		= kMaxHoursInDay * kMaxMinutsInHour; 

static const char kAnteMeridiemMessage[]	= " a.m.";
static const char kPostMeridiemMessage[]	= " p.m.";
static const char kMinutesFormatMessage[]	= " minute(s)";

enum TimeStateEnum
{
	// Time format 
	kUseFullCircleHoursMask		= 1 << 0, /**< enum value 1 << 0 (1). */
	kUseHalfCircleHoursMask		= 1 << 1, /**< enum value 1 << 1 (2). */
	kUseMinutesOnlyMask			= 1 << 2, /**< enum value 1 << 2 (4). */

	// Time value
	kIsAddLastOperationMask		= 1 << 3, /**< enum value 1 << 3 (8). */
	kIsMinusLastOperationMask	= 1 << 4, /**< enum value 1 << 4 (16). */
};

// ****************************************************************************
// ***  Implementation of public methods of class
// ****************************************************************************

Time::Time(MinutsCountType aMinuts)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::Time(aMinuts = %i) - called\n", this, aMinuts);
#endif
	aMinuts = aMinuts % kMaxMinutsInDay;

	_stringFormat = NULL;
	_minutes = new MinutsCountType(aMinuts);
	_state = new OptionType(kUseMinutesOnlyMask | kIsAddLastOperationMask);
}

Time::Time(HoursCountType aHours, MinutsCountType aMinuts)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::Time(aHours = %i, aMinuts = %i) - called\n", this, aHours, aMinuts);
#endif
	_stringFormat = NULL;
	_minutes = new MinutsCountType;
	_state = new OptionType;

	aHours = aHours % kMaxHoursInDay;
	aMinuts = aMinuts % kMaxMinutsInHour;
	*_minutes = aHours * kMaxMinutsInHour + aMinuts;
	*_state = kUseFullCircleHoursMask | kIsAddLastOperationMask;
}

Time::Time(HoursCountType aHours, MinutsCountType aMinuts, bool isAMTimeValue)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::Time(aHours = %i, aMinuts = %i, isAMTimeValue = %s) called\n", 
		this, aHours, aMinuts, isAMTimeValue ? "true" : "false");
#endif
	_stringFormat = NULL;
	_minutes = new MinutsCountType;
	_state = new OptionType;

	aHours = aHours % kMaxHoursInAMPMMode;
	if (!isAMTimeValue)
	{
		aHours += kMaxHoursInAMPMMode;
	}
	aMinuts = aMinuts % kMaxMinutsInHour;
	*_minutes = aHours * kMaxMinutsInHour + aMinuts;
	*_state = kUseHalfCircleHoursMask | kIsAddLastOperationMask;
}

Time::Time(const Time& rhs)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::Time(const Time& rhs = %p) - called\n", this, &rhs);
#endif
	_minutes = new MinutsCountType(*rhs._minutes);
	_state = new OptionType(*rhs._state);
	
	_stringFormat = NULL;
	if (NULL != rhs._stringFormat)
	{
		_stringFormat = new char[strlen(rhs._stringFormat) + 1];
		strcpy(_stringFormat, rhs._stringFormat);
	}
}

Time::~Time()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::~Time() - called\n", this);
#endif
	delete[] _stringFormat;
	delete _minutes;
	delete _state;
}

Time& Time::operator = (const Time& rhs)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::operator = (const Time& rhs = %p) - called\n", this, &rhs);
#endif
	if (this == &rhs)
	{
		return *this;
	}

	*_minutes = *rhs._minutes;
	*_state = *rhs._state;

	delete[] _stringFormat;
	_stringFormat = NULL;
	if (NULL != rhs._stringFormat)
	{
		_stringFormat = new char[strlen(rhs._stringFormat) + 1];
		strcpy(_stringFormat, rhs._stringFormat);
	}
}

bool Time::isOnlyMinutsFormat() const
{
	return ((*_state) & kUseMinutesOnlyMask) != 0;
}

bool Time::is24HoursFormat() const
{
	return ((*_state) & kUseFullCircleHoursMask) != 0;
}

bool Time::is12HoursFormat() const
{
	return ((*_state) & kUseHalfCircleHoursMask) != 0;
}

HoursCountType Time::getHours() const
{
	HoursCountType result = *_minutes / kMaxMinutsInHour;
	if (is12HoursFormat())
	{
		result %= kMaxHoursInAMPMMode;
		result = 0 == result ? kMaxHoursInAMPMMode : result;
	}
	return result;
}

MinutsCountType Time::getMinuts() const
{
	return isOnlyMinutsFormat() ? *_minutes : *_minutes % kMaxMinutsInHour;
}

bool Time::isAMTimeValue() const
{
	HoursCountType hours = *_minutes / kMaxMinutsInHour;
	return 0 == hours / kMaxHoursInAMPMMode;
}

bool Time::isAddTimeLastOparation() const
{
	return *_state & kIsAddLastOperationMask;
}

#ifndef SHOW_WORK_WITH_REFERENCES
void Time::addTime(const Time aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::addTime(const Time aTime) - called\n", this);
#endif
	*_minutes += *aTime._minutes;
	refrashContentDataForAddOperation(true);
}
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
void Time::addTime(const Time& aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::addTime(const Time& aTime = %p) - called\n", this, &aTime);
#endif
	*_minutes += *aTime._minutes;
	refrashContentDataForAddOperation(true);
}
#endif

void Time::addTime(const Time* const aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::addTime(const Time* const aTime = %p) - called\n", this, aTime);
#endif
	*_minutes += *aTime->_minutes;
	refrashContentDataForAddOperation(true);
}

#ifndef SHOW_WORK_WITH_REFERENCES
void Time::minusTime(const Time aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::minusTime(const Time aTime) - called\n", this);
#endif
	*_minutes -= *aTime._minutes;
	refrashContentDataForAddOperation(false);
}
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
void Time::minusTime(const Time& aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::minusTime(const Time& aTime = %p) - called\n", this, &aTime);
#endif
	*_minutes -= *aTime._minutes;
	refrashContentDataForAddOperation(false);
}
#endif

void Time::minusTime(const Time* const aTime)
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::minusTime(const Time* const aTime = %p) - called\n", this, aTime);
#endif
	*_minutes -= *aTime->_minutes;
	refrashContentDataForAddOperation(false);
}

const char* const Time::getStringValue()
{
	if (NULL == _stringFormat)		// lazy initialization
	{
		_stringFormat = createStringFormat();
	}
	return _stringFormat;
}

// ****************************************************************************
// ***  Implementation of private methods of class
// ****************************************************************************

Time::Time()
{
#ifdef SHOW_DEBUG_MESSAGES
	printf("%p - Time::Time() - called !!!!!!!!!!!!!!\n", this);
#endif
	_minutes = NULL;
	_state = NULL;
}

void Time::refrashContentDataForAddOperation(bool isAddPerformed)
{
	if (*_minutes < 0)
	{
		*_minutes += kMaxMinutsInDay;
	}
	*_minutes %= kMaxMinutsInDay;
	if (isAddTimeLastOparation() != isAddPerformed)
	{
		changeStateOfLastOperation();
	}
	delete[] _stringFormat;
	_stringFormat = NULL;
}

void Time::changeStateOfLastOperation()
{
	*_state ^= kIsAddLastOperationMask;
	*_state ^= kIsMinusLastOperationMask;
}

char* Time::createStringFormat() const
{
	char* result = NULL;
	if (is24HoursFormat())
	{
		char hoursString[3] = "";
		char minutesString[3] = "";
		itoa(getHours(), hoursString, 10);
		itoa(getMinuts(), minutesString, 10);

		// 1 character for '\0' and 1 - for ':'
		result = new char[strlen(hoursString) + strlen(minutesString) + 2];	
		strcpy(result, hoursString);
		strcat(result, ":");
		strcat(result, minutesString);
	}
	else if (is12HoursFormat())
	{
		HoursCountType hours = getHours();
		hours = 0 == hours ? kMaxHoursInAMPMMode : hours;

		char hoursString[3] = "";
		char minutesString[3] = "";
		const char* meridiemString = isAMTimeValue() ? kAnteMeridiemMessage : kPostMeridiemMessage;

		itoa(hours, hoursString, 10);
		itoa(getMinuts(), minutesString, 10);

		// 1 character for '\0' and 1 - for ':'
		result = new char[strlen(hoursString) + strlen(minutesString) + strlen(meridiemString) + 2];	
		strcpy(result, hoursString);
		strcat(result, ":");
		strcat(result, minutesString);
		strcat(result, meridiemString);
	}
	else if (isOnlyMinutsFormat())
	{
		char minutesString[5] = "";
		itoa(getMinuts(), minutesString, 10);
		result = new char[strlen(minutesString) + strlen(kMinutesFormatMessage) + 1];
		strcpy(result, minutesString);
		strcat(result, kMinutesFormatMessage);
	}

	return result;
}

// ****************************************************************************
// ***  Implamentation of support methods
// ****************************************************************************

#ifndef SHOW_WORK_WITH_REFERENCES
SignedMinutsCountType DifferenceBetweenTimes(const Time aTimeLeft, const Time aTimeRight)
{
	MinutsCountType minutesLeft = 0;
	if (aTimeLeft.isOnlyMinutsFormat())
	{
		minutesLeft = aTimeLeft.getMinuts();
	}
	else if (aTimeLeft.is24HoursFormat())
	{
		minutesLeft = aTimeLeft.getHours() * kMaxMinutsInHour + aTimeLeft.getMinuts();
	}
	else if (aTimeLeft.is12HoursFormat())
	{
		HoursCountType hours = aTimeLeft.getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeLeft.isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesLeft = hours * kMaxMinutsInHour + aTimeLeft.getMinuts();
	}

	MinutsCountType minutesRight = 0;
	if (aTimeRight.isOnlyMinutsFormat())
	{
		minutesRight = aTimeRight.getMinuts();
	}
	else if (aTimeRight.is24HoursFormat())
	{
		minutesRight = aTimeRight.getHours() * kMaxMinutsInHour + aTimeRight.getMinuts();
	}
	else if (aTimeRight.is12HoursFormat())
	{
		HoursCountType hours = aTimeRight.getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeRight.isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesRight = hours * kMaxMinutsInHour + aTimeRight.getMinuts();
	}

	return minutesLeft - minutesRight;
}
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
SignedMinutsCountType DifferenceBetweenTimes(const Time& aTimeLeft, const Time& aTimeRight)
{
	MinutsCountType minutesLeft = 0;
	if (aTimeLeft.isOnlyMinutsFormat())
	{
		minutesLeft = aTimeLeft.getMinuts();
	}
	else if (aTimeLeft.is24HoursFormat())
	{
		minutesLeft = aTimeLeft.getHours() * kMaxMinutsInHour + aTimeLeft.getMinuts();
	}
	else if (aTimeLeft.is12HoursFormat())
	{
		HoursCountType hours = aTimeLeft.getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeLeft.isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesLeft = hours * kMaxMinutsInHour + aTimeLeft.getMinuts();
	}

	MinutsCountType minutesRight = 0;
	if (aTimeRight.isOnlyMinutsFormat())
	{
		minutesRight = aTimeRight.getMinuts();
	}
	else if (aTimeRight.is24HoursFormat())
	{
		minutesRight = aTimeRight.getHours() * kMaxMinutsInHour + aTimeRight.getMinuts();
	}
	else if (aTimeRight.is12HoursFormat())
	{
		HoursCountType hours = aTimeRight.getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeRight.isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesRight = hours * kMaxMinutsInHour + aTimeRight.getMinuts();
	}

	return minutesLeft - minutesRight;
}
#endif

SignedMinutsCountType DifferenceBetweenTimes(const Time* const aTimeLeft, const Time* const aTimeRight)
{
	MinutsCountType minutesLeft = 0;
	if (aTimeLeft->isOnlyMinutsFormat())
	{
		minutesLeft = aTimeLeft->getMinuts();
	}
	else if (aTimeLeft->is24HoursFormat())
	{
		minutesLeft = aTimeLeft->getHours() * kMaxMinutsInHour + aTimeLeft->getMinuts();
	}
	else if (aTimeLeft->is12HoursFormat())
	{
		HoursCountType hours = aTimeLeft->getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeLeft->isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesLeft = hours * kMaxMinutsInHour + aTimeLeft->getMinuts();
	}

	MinutsCountType minutesRight = 0;
	if (aTimeRight->isOnlyMinutsFormat())
	{
		minutesRight = aTimeRight->getMinuts();
	}
	else if (aTimeRight->is24HoursFormat())
	{
		minutesRight = aTimeRight->getHours() * kMaxMinutsInHour + aTimeRight->getMinuts();
	}
	else if (aTimeRight->is12HoursFormat())
	{
		HoursCountType hours = aTimeRight->getHours();
		if (kMaxHoursInAMPMMode == hours)
		{
			hours = 0;
		}
		if (!aTimeRight->isAMTimeValue())
		{
			hours += kMaxHoursInAMPMMode;
		}

		minutesRight = hours * kMaxMinutsInHour + aTimeRight->getMinuts();
	}

	return minutesLeft - minutesRight;
}


