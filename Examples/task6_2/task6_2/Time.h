#ifndef TIME_H
#define TIME_H

/** 
 * @file Time.h
 * @brief This file provides an interface to work with the class 'Time'
 */

#include "ProjectSupport.h"

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

/** 
 * @var typedef	int SignedMinutsCountType
 * @brief A variables that the stored signed value of minutes, must be current type
 */
typedef long int SignedMinutsCountType;

/** 
 * @var typedef	int MinutsCountType
 * @brief A variables that the stored unsigned value of minutes, must be current type
 */
typedef unsigned int MinutsCountType;

/** 
 * @var typedef	int HoursCountType
 * @brief A variables that the stored unsigned value of hours, must be current type
 */
typedef unsigned int HoursCountType;

/**
 * @var extern const HoursCountType kMaxHoursInAMPMMode
 * @brief This variable is the maximum number of hours in 12 hour mode
 */
extern const HoursCountType kMaxHoursInAMPMMode; 

/**
 * @var extern const HoursCountType kMaxHoursInDay
 * @brief This variable is the maximum number of hours in a 24 hour mode
 */
extern const HoursCountType kMaxHoursInDay; 

/**
 * @var extern const MinutsCountType kMaxMinutsInHour
 * @brief This variable is the maximum number of minutes in one hour
 */
extern const MinutsCountType kMaxMinutsInHour; 

/**
 * @var extern const MinutsCountType kMaxMinutsInDay
 * @brief This variable is the maximum number of minutes per day
 */
extern const MinutsCountType kMaxMinutsInDay; 

// ****************************************************************************
// ***  Interface of class
// ****************************************************************************

/** 
 * @class Time
 * @brief This class you can use for store time in different formats and
 * make some operation with it.
 */
class Time
{
public:
	/**
	 * @brief This constructor we use for setup object that show 
	 * us the information in minets format only.
     * @param aMinuts - an integer argument.
     */
	Time(MinutsCountType aMinuts);

	/**
	 * @brief This constructor we use for setup object that show 
	 * us the information in 24 hours formats.
     * @param aHours - an integer argument.
     * @param aMinuts - an integer argument.
     */
	Time(HoursCountType aHours, MinutsCountType aMinuts);

	/**
	 * @brief This constructor we use for setup object that show 
	 * us the information in 12 hours formats.
     * @param aHours - an integer argument.
     * @param aMinuts - an integer argument.
     * @param isAMTimeValue - a boolean argument.
     */
	Time(HoursCountType aHours, MinutsCountType aMinuts, bool isAMTimeValue);

	/**
     * @brief A copy-constructor.
     * @param rhs - a reference on Time object argument.
     */
	Time(const Time& rhs);

	/**
     * @brief A destructor.
     */
	~Time();

	/**
     * @brief A overriden assign-operator.
     * @param rhs - a reference on Time object argument.
	 * @return The reference on self.
     */
	Time& operator = (const Time& rhs);

	/**
	 * @brief Return true value if object is represented in minutes format.
	 * @return The boolean value.
     */
	bool isOnlyMinutsFormat() const;

	/**
	 * @brief Return true value if object is represented in 24 hours format.
	 * @return The boolean value.
     */
	bool is24HoursFormat() const;

	/**
	 * @brief Return true value if object is represented in 12 hours format.
	 * @return The boolean value.
     */
	bool is12HoursFormat() const;

	/**
	 * @brief Return hours count for correspond hours format.
	 * @return The HoursCountType value.
     */
	HoursCountType getHours() const;

	/**
	 * @brief Return minutes count for correspond time format.
	 * @return The MinutsCountType value.
     */
	MinutsCountType getMinuts() const;

	/**
	 * @brief Call this method to know what half of the day right now.
	 * @return The boolean value.
     */
	bool isAMTimeValue() const;

	/**
	 * @brief Call this method to know what was the last operation.
	 * @return The boolean value.
     */
	bool isAddTimeLastOparation() const;

#ifndef SHOW_WORK_WITH_REFERENCES
	/**
	 * @brief Use this method for increase time value from argument.
	 * @param aTime - a Time object argument.
     */
	void addTime(const Time aTime);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
	/**
	 * @brief Use this method for increase time value from argument.
	 * @param aTime - a reference on Time object argument.
     */
	void addTime(const Time& aTime);
#endif

	/**
	 * @brief Use this method for increase time value from argument.
	 * @param aTime - a pointer on Time object argument.
     */
	void addTime(const Time* const aTime);

#ifndef SHOW_WORK_WITH_REFERENCES
	/**
	 * @brief Use this method for decrease time value from argument.
	 * @param aTime - a Time object argument.
     */
	void minusTime(const Time aTime);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
	/**
	 * @brief Use this method for decrease time value from argument.
	 * @param aTime - a reference on Time object argument.
     */
	void minusTime(const Time& aTime);
#endif

	/**
	 * @brief Use this method for decrease time value from argument.
	 * @param aTime - a pointer on Time object argument.
     */
	void minusTime(const Time* const aTime);

	/**
	 * @brief Return full time string value in correspond format.
	 * @return The pointer on char array value.
     */
	const char* const getStringValue();

private:

	/** 
	 * @var typedef unsigned int OptionType
	 * @brief For using value from TimeStateEnum you need use variable with current type
	 * @see TimeStateEnum
	 */
	typedef unsigned int OptionType;

	/**
	 * @brief A default constructor. This constructor is private, so we never create object by it.
     */
	Time();

	/**
	 * @brief Call this method when minuts value was applied by add or minus operation,
	 * and we need update dependent variables.
	 * @see addTime()
	 * @see minusTime()
	 * @param isAddPerformed - a boolean argument.
     */
	void refrashContentDataForAddOperation(bool isAddPerformed);

	/**
	 * @brief Call this method when you need correctly change state of last operation.
     */
	void changeStateOfLastOperation();

	/**
	 * @brief Create and return full time string value in correspond format.
	 * @return The pointer on char array value.
     */
	char* createStringFormat() const;

	/** 
     * @brief Keep time value in minutes format
     */
	MinutsCountType* _minutes;

	/** 
     * @brief Keep time format and last operation
     */
	OptionType* _state;

	/** 
     * @brief Keep time format and last operation
     */
	char* _stringFormat;
};

// ****************************************************************************
// ***  Interface of support methods
// ****************************************************************************

#ifndef SHOW_WORK_WITH_REFERENCES
/** 
 * @brief Calculate difference between two time objects
 * @param aTimeLeft - a Time object argument.
 * @param aTimeRight - a Time object argument.
 * @return SignedMinutsCountType - numerical value.
 */
SignedMinutsCountType DifferenceBetweenTimes(const Time aTimeLeft, const Time aTimeRight);
#endif

#ifdef SHOW_WORK_WITH_REFERENCES
/** 
 * @brief Calculate difference between two time objects
 * @param aTimeLeft - a reference on Time object argument.
 * @param aTimeRight - a reference on Time object argument.
 * @return SignedMinutsCountType - numerical value.
 */
SignedMinutsCountType DifferenceBetweenTimes(const Time& aTimeLeft, const Time& aTimeRight);
#endif

/** 
 * @brief Calculate difference between two time objects
 * @param aTimeLeft - a reference on Time object argument.
 * @param aTimeRight - a reference on Time object argument.
 * @return SignedMinutsCountType - numerical value.
 */
SignedMinutsCountType DifferenceBetweenTimes(const Time* const aTimeLeft, const Time* const aTimeRight);

#endif
