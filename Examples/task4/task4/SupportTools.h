/*
		#pragma once - it is new method for including *.h files only once,
	but it may not work in some compilators, so we will use the second way
	with preprocesors difining.
		This method also has some negatives (for example the key that we 
	defining may exists in current time, as result we will have compile errors), 
	but in this case we can get some experience with preprocesors difining.
*/
//#pragma once			     

#ifndef SUPPORT_TOOLS_H
#define SUPPORT_TOOLS_H

#include <conio.h>

// ****************************************************************************
// ***  Constants and types
// ****************************************************************************

/*
	To tell the truth we need write next lines here:
extern int const maxRowsSize;
extern int const maxColumnsSize;

	And in .m file next lines:
static int const maxRowsSize = 20;
static int const maxColumnsSize = 20;

	But in our function we set 'double matrix[maxRowsSize][maxColumnsSize]',
	where 'maxRowsSize' and 'maxColumnsSize' must be const and well known value.
	In our case they are const, but the value is 0 and will setted to 20 only
	in execution programm.
*/
static int const maxRowsSize = 20;
static int const maxColumnsSize = 20;

// ****************************************************************************
// ***  Interface of functions
// ****************************************************************************

void InputMatrixByKeyboard(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns);
void SetupMatrixRandomly(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, const double inBeginInterval = -100.0, const double inEndInterval = 100.0);
void PrintMatrix(const double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns);
void SetupMatrixToZero(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns);
void MakeSortForMatrix(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, const bool inIsAscending = true);
void ShiftMatrix(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, int inShiftValue);

bool MakeCheckForNumberInputFromCin(const char inErrorMessage[]);

#endif