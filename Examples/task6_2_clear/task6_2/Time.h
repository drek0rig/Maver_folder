#ifndef TIME_H
#define TIME_H

#include "ProjectSupport.h"

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

typedef long int SignedMinutsCountType;
typedef unsigned int MinutsCountType;
typedef unsigned int HoursCountType;

extern const HoursCountType kMaxHoursInAMPMMode; 
extern const HoursCountType kMaxHoursInDay; 
extern const MinutsCountType kMaxMinutsInHour; 
extern const MinutsCountType kMaxMinutsInDay; 

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

class Time
{
public:
	Time(MinutsCountType aMinuts);
	Time(HoursCountType aHours, MinutsCountType aMinuts);
	Time(HoursCountType aHours, MinutsCountType aMinuts, bool isAMTimeValue);
	Time(const Time& rhs);
	~Time();

	Time& operator = (const Time& rhs);

	bool isOnlyMinutsFormat() const;
	bool is24HoursFormat() const;
	bool is12HoursFormat() const;

	HoursCountType getHours() const;
	MinutsCountType getMinuts() const;
	bool isAMTimeValue() const;
	bool isAddTimeLastOparation() const;

#ifndef SHOW_WORK_WITH_REFERENCES
	void addTime(const Time aTime);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
	void addTime(const Time& aTime);
#endif

	void addTime(const Time* const aTime);

#ifndef SHOW_WORK_WITH_REFERENCES
	void minusTime(const Time aTime);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
	void minusTime(const Time& aTime);
#endif

	void minusTime(const Time* const aTime);

	const char* const getStringValue();

	friend SignedMinutsCountType DifferenceBetweenTimes(const Time* const aTimeLeft, const Time* const aTimeRight);

private:
	typedef unsigned int OptionType;

	Time();

	void refrashContentDataForAddOperation(bool isAddPerformed);
	void changeStateOfLastOperation();
	char* createStringFormat() const;

	MinutsCountType* _minutes;
	OptionType* _state;
	char* _stringFormat;
};

// ****************************************************************************
// ***  Interface of support methods
// ****************************************************************************

#ifndef SHOW_WORK_WITH_REFERENCES
SignedMinutsCountType DifferenceBetweenTimes(const Time aTimeLeft, const Time aTimeRight);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
SignedMinutsCountType DifferenceBetweenTimes(const Time& aTimeLeft, const Time& aTimeRight);
#endif



#endif
