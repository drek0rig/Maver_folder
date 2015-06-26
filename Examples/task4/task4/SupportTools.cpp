#include "SupportTools.h"
#include <iostream>
#include <ctime>

using namespace std;

// ****************************************************************************
// ***  Locale constants and types
// ****************************************************************************

static const char kInputMatrixElementsString[] = "Input matrix elements\n";
static const char kPrintMatrixElementFormatString[] = "Matrix[%i][%i] = ";
static const char kPleaseEnterDoubleValueOnly[] = "Please enter double value only.\n";

// ****************************************************************************
// ***  Implementation of public functions
// ****************************************************************************

void InputMatrixByKeyboard(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns)
{
    printf(kInputMatrixElementsString);
    for (int row = 0; row < inRows; row++)
	{
        for (int column = 0; column < inColumns; column++)
        {
			bool isCorrectValue = false;
			while (!isCorrectValue)
			{
		        printf(kPrintMatrixElementFormatString, row + 1, column + 1);
				cin >> matrix[row][column];
				isCorrectValue = MakeCheckForNumberInputFromCin(kPleaseEnterDoubleValueOnly);
			}
        }
	}
}

void SetupMatrixRandomly(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, const double inBeginInterval, const double inEndInterval)
{
	double intervalValue = fabs(inEndInterval - inBeginInterval);
    srand((unsigned int)time(NULL));  // Setup random range
    for (int row = 0; row < inRows; row++)
	{
        for (int column = 0; column < inColumns; column++)
        {
			double randomNumber = rand() / (double)RAND_MAX; // between values [0..1] in percents
			randomNumber *= intervalValue;
			randomNumber += inBeginInterval;
            matrix[row][column] = randomNumber;
        }
	}
}

void PrintMatrix(const double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns)
{
    for (int row = 0; row < inRows; row++)
    {
        printf("[");
        for (int column = 0; column < inColumns; column++)
        {
            printf("%0.2lf", matrix[row][column]);
			if (column < inColumns - 1)
				printf(" ");
        }	
        printf("]\n");
    }
}

void SetupMatrixToZero(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns)
{
    for (int row = 0; row < inRows; row++)
    {
        for (int column = 0; column < inColumns; column++)
        {
            matrix[row][column] = 0;
        }	
    }
}

void MakeSortForMatrix(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, const bool inIsAscending)
{
	for (int iterationCount = 0; iterationCount < inRows * inColumns - 1; iterationCount++)
	{
        for (int elementIndex = iterationCount; elementIndex < inRows*inColumns; elementIndex++)
        {
			double startIterationElement = matrix[iterationCount/inColumns][iterationCount%inColumns];
			double currentIterationElement = matrix[elementIndex/inColumns][elementIndex%inColumns];
            if ((inIsAscending && startIterationElement > currentIterationElement) ||
                (!inIsAscending && startIterationElement < currentIterationElement))
            {
				matrix[iterationCount/inColumns][iterationCount%inColumns] = currentIterationElement;
				matrix[elementIndex/inColumns][elementIndex%inColumns] = startIterationElement;
            }	
        }
	}
}

void ShiftMatrix(double matrix[maxRowsSize][maxColumnsSize], const int inRows, const int inColumns, int inShiftValue)
{
	// If shift value is bigger than inRows*inColumns, as result we made 
	// no need rotations, so make smaller value
	int elementsCount = inRows*inColumns;
	inShiftValue = inShiftValue % elementsCount;
	if (!inShiftValue)  // as result 
		return;			
	if (inShiftValue < 0)
		inShiftValue = elementsCount + inShiftValue ;

	int tempMassiveSize = 0;
	double tempMassive[maxRowsSize*maxColumnsSize / 2];
	if (inShiftValue >= elementsCount / 2)
	{
		tempMassiveSize = elementsCount - inShiftValue;
		for (int elementIndex = 0; elementIndex < tempMassiveSize; elementIndex++)
		{
			tempMassive[elementIndex] = matrix[elementIndex/inColumns][elementIndex%inColumns];
		}

		for (int elementIndex = 0; elementIndex < inShiftValue; elementIndex++)
		{
			matrix[elementIndex/inColumns][elementIndex%inColumns] = 
				matrix[(elementIndex + tempMassiveSize)/inColumns][(elementIndex + tempMassiveSize)%inColumns];
		}

		for (int elementIndex = 0; elementIndex < tempMassiveSize; elementIndex++)
		{
			matrix[(elementIndex + inShiftValue)/inColumns][(elementIndex + inShiftValue)%inColumns] = tempMassive[elementIndex];
		}
	}
	else 
	{
		tempMassiveSize = inShiftValue;
		for (int elementIndex = elementsCount - inShiftValue; elementIndex < elementsCount; elementIndex++)
		{
			tempMassive[elementIndex - elementsCount + inShiftValue] = matrix[elementIndex/inColumns][elementIndex%inColumns];
		}

		for (int elementIndex = elementsCount; elementIndex >= inShiftValue; elementIndex--)
		{
			matrix[elementIndex/inColumns][elementIndex%inColumns] = 
				matrix[(elementIndex - inShiftValue)/inColumns][(elementIndex - inShiftValue)%inColumns];
		}

		for (int elementIndex = 0; elementIndex < inShiftValue; elementIndex++)
		{
			matrix[elementIndex/inColumns][elementIndex%inColumns] = tempMassive[elementIndex];
		}
	}
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

