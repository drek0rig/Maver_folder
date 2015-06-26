#include "Time.h"

#ifdef NEED_FIND_LEAKS
#include <crtdbg.h>
#include <cstdio>
#endif

// ****************************************************************************
// ***  Interface of local fuctions
// ****************************************************************************

/** 
 * In this function we check correct work of class getters
 * in different time formats
 * @brief First stage of testing
 */
void TestFunction1();

/** 
 * In this function we check correct work of operation methods
 * with different time formats
 * @brief Second stage of testing
 */
void TestFunction2();

/** 
 * In this function we check correct work of 'DifferenceBetweenTimes' methods
 * with different time formats
 * @brief Third stage of testing
 */
void TestFunction3();

/** 
 * @brief Traditional main function with all main code
 * @return int - status value of execution application.
 */
int main()
{
	{
		printf("\n\n***************************************************************\n\n");
		TestFunction1();
		printf("\n\n***************************************************************\n\n");
		TestFunction2();
		printf("\n\n***************************************************************\n\n");
		TestFunction3();
		printf("\n\n***************************************************************\n\n");
	}

#ifdef NEED_FIND_LEAKS
    if (_CrtDumpMemoryLeaks())
    {
		printf("!!! There are some leaks. See 'Output' window in Visual Stusio.\n");
		getchar();
    }
#endif
	return 0;
}

// ****************************************************************************
// ***  Implementation of local fuctions
// ****************************************************************************

void TestFunction1()
{
	printf("TestFunction1() called !\n\n");


	printf("Creating 'theTimeWithMinuts' object with minuts format only\n");

	Time theTimeWithMinuts(2*kMaxMinutsInHour + 31);
	printf("theTimeWithMinuts.isOnlyMinutsFormat() = %s\n", 
		theTimeWithMinuts.isOnlyMinutsFormat() ? "true" : "false");
	printf("theTimeWithMinuts.is24HoursFormat() = %s\n", 
		theTimeWithMinuts.is24HoursFormat() ? "true" : "false");
	printf("theTimeWithMinuts.is12HoursFormat() = %s\n", 
		theTimeWithMinuts.is12HoursFormat() ? "true" : "false");
	printf("theTimeWithMinuts.getHours() = %lu\n", theTimeWithMinuts.getHours());
	printf("theTimeWithMinuts.getMinuts() = %lu\n", theTimeWithMinuts.getMinuts());
	printf("theTimeWithMinuts.isAMTimeValue() = %s\n", 
		theTimeWithMinuts.isAMTimeValue() ? "true" : "false");
	printf("theTimeWithMinuts.getStringValue() = '%s'\n", theTimeWithMinuts.getStringValue());


	printf("\nCreating 'the24Time' object in 24 hours format\n");

	Time the24Time(15, 23);
	printf("the24Time.isOnlyMinutsFormat() = %s\n", 
		the24Time.isOnlyMinutsFormat() ? "true" : "false");
	printf("the24Time.is24HoursFormat() = %s\n", 
		the24Time.is24HoursFormat() ? "true" : "false");
	printf("the24Time.is12HoursFormat() = %s\n", 
		the24Time.is12HoursFormat() ? "true" : "false");
	printf("the24Time.getHours() = %lu\n", the24Time.getHours());
	printf("the24Time.getMinuts() = %lu\n", the24Time.getMinuts());
	printf("the24Time.isAMTimeValue() = %s\n", 
		the24Time.isAMTimeValue() ? "true" : "false");
	printf("the24Time.getStringValue() = '%s'\n", the24Time.getStringValue());


	printf("\nCreating 'the12Time' object in 12 hours format\n");

	Time the12Time(10, 26, false);
	printf("the12Time.isOnlyMinutsFormat() = %s\n", 
		the12Time.isOnlyMinutsFormat() ? "true" : "false");
	printf("the12Time.is24HoursFormat() = %s\n", 
		the12Time.is24HoursFormat() ? "true" : "false");
	printf("the12Time.is12HoursFormat() = %s\n", 
		the12Time.is12HoursFormat() ? "true" : "false");
	printf("the12Time.getHours() = %lu\n", the12Time.getHours());
	printf("the12Time.getMinuts() = %lu\n", the12Time.getMinuts());
	printf("the12Time.isAMTimeValue() = %s\n", 
		the12Time.isAMTimeValue() ? "true" : "false");
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());


	printf("\nTestFunction1() exiting!\n");
}

void TestFunction2()
{
	printf("TestFunction2() called !\n\n");

	printf("Creating 'theTimeWithMinuts' object with minuts format only\n");
	Time theTimeWithMinuts(kMaxHoursInAMPMMode*kMaxMinutsInHour - 26);
	printf("Creating 'the12Time' object in 12 hours format\n");
	Time the12Time(10, 26, true);

	printf("\nBefore adding objects\n");
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());
	printf("Adding 'theTimeWithMinuts' to 'the12Time' object\n");
	the12Time.addTime(theTimeWithMinuts);
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());

	printf("\nMake difference between 'the12Time' and 'theTimeWithMinuts' objects\n");
	the12Time.minusTime(theTimeWithMinuts);
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());

	
	printf("\nSecond try of adding objects\n");
	printf("the12Time.addTime(&theTimeWithMinuts); called\n");
	the12Time.addTime(&theTimeWithMinuts);
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());

	printf("\nthe12Time.minusTime(&theTimeWithMinuts);\n");
	the12Time.minusTime(&theTimeWithMinuts);
	printf("the12Time.getStringValue() = '%s'\n", the12Time.getStringValue());


	printf("\nTestFunction2() exiting!\n");
}

void TestFunction3()
{
	printf("TestFunction3() called !\n\n");

	printf("Creating dynamic 'theTimeWithMinuts' object with minuts format only\n");
	Time* theTimeWithMinuts = new Time(kMaxHoursInAMPMMode*kMaxMinutsInHour - 26);
	printf("Creating dynamic 'the12Time' object in 12 hours format\n");
	Time* the12Time = new Time(10, 26, true);

	printf("\ntheTimeWithMinuts.getStringValue() = '%s'\n", theTimeWithMinuts->getStringValue());
	printf("the12Time.getStringValue() = '%s'\n", the12Time->getStringValue());

	printf("\nDifferenceBetweenTimes(theTimeWithMinuts, the12Time) called !\n");
	printf("Result = %li\n", DifferenceBetweenTimes(theTimeWithMinuts, the12Time));

	printf("DifferenceBetweenTimes(*the12Time, *theTimeWithMinuts) called !\n");
	printf("Result = %li\n", DifferenceBetweenTimes(*the12Time, *theTimeWithMinuts));

	printf("\nRemoving dynamic 'theTimeWithMinuts' object\n");
	delete theTimeWithMinuts;
	printf("Removing dynamic 'the12Time' object\n");
	delete the12Time;

	printf("\nTestFunction3() exiting!\n");
}
