#ifndef TIME_H
#define TIME_H
#pragma once

#include "SupportTools.h"

// ****************************************************************************
// ***  Local constants and types
// ****************************************************************************

extern const int kMinTimeValue;
extern const int kMaxTimeValue;
extern const int kMaxReturnStringValueLenth;

typedef enum
{
	MinutesType				= 1,
	TwelfthHourType			= 2,
	TwentyFoureHourType		= 3,
	DefaultHourType			= MinutesType,
	MaxTimeMeasurementType  = TwentyFoureHourType
} TimeMeasurementType;

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Time
{
public:
	Time();
	Time(int time, TimeMeasurementType timeType = DefaultHourType, bool operationExist = true);
	Time(const Time&);
	~Time();
	Time& operator=(const Time&);
	
	void setTime(const int time);
	int getTime() const;
	int getTimeMinutes() const;
	int getTimeHours() const;

	char* getStringValue() const;

	void setTimeType(const TimeMeasurementType timeType);
	TimeMeasurementType getTimeType() const;

	bool isAddTimeLastOperation() const;
	void addTime(const Time* const pAddingTime);
	void minusTime (const Time* const pminusTime);

private:
	int* _time;
	TimeMeasurementType* _timeType;
	bool _operationExist;
};

// ****************************************************************************
// ***  Interface of functions
// ****************************************************************************

char* DifferenceBetweenTimes(const Time* const pTimeOne, const Time* const pTimeTwo);
char* DifferenceBetweenTimes(const Time& rTimeOne, const Time& rTimeTwo);

#endif