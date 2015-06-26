#include "SupportTools.h"
#include <ctime>
#include <utility>
#include <stdio.h>
#include <cstdlib>

using namespace std;

LOC kMenu[] =			"* * Menu * *";
LOC kValuesInput[] =	"(1) Input values of matrix elements.";
LOC kOutputToScreen[] =	"(2) Output a matrix to the screen.";
LOC kZeroing[] =		"(3) Zeroing matrix.";
LOC kSort[] =			"(4) Sort.";
LOC kCyclicShift[] =	"(5) Perform cyclic shift elements.";
LOC kExit[] =			"(6) Exit.";

int menu()  // Функція виводу основного меню
{
	int choise;

	printf("%s\n", kMenu);
	printf("%s\n", kValuesInput);
	printf("%s\n", kOutputToScreen);
	printf("%s\n", kZeroing);
	printf("%s\n", kSort);
	printf("%s\n", kCyclicShift);
	printf("%s\n\n", kExit);
	printf(":");
	scanf("%d", &choise);

	return choise;
}

void RandomMatrixFilling(int Array[matrixSize][matrixSize], int mSize) // Функція рандомного заповнення матриці 
{
	srand(time(NULL));
	for(int i = 0; i < mSize; i++)
	{
		for(int j = 0; j < mSize; j++)
		{
			Array[i][j] = rand() % 201 - 100;
		}
	}	
}

void KeyboardMatrixFilling(int Array[matrixSize][matrixSize], int mSize)  // Заповнення матриці з клавіатури
{
	for(int i = 0; i < mSize; i++)
	{
		for(int j = 0; j < mSize; j++)
		{
			printf("Enter a value of element[%d][%d]:", i, j);
			scanf("%d", &Array[i][j]);
		}
		printf("\n");
	}
}

void PrintMatrix(int Array[matrixSize][matrixSize], int mSize)	// Друк матриці
{
	for(int i = 0; i < mSize; i++)
	{
		for(int j = 0; j < mSize; j++)
		{
			printf("%d\t", Array[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void ZeroingMatrix(int Array[matrixSize][matrixSize], int mSize)	// Занулення матриці
{
	for(int i = 0; i < mSize; i++)
	{
		for(int j = 0; j < mSize; j++)
		{
			Array[i][j] = 0;
		}
	}	
}

void SelectionSort(int Array[matrixSize][matrixSize], int mSize)	// Сортування вибором
{
	int elementCount = mSize * mSize;
	for (int iterationCount = 0; iterationCount < elementCount; iterationCount++)
	{
		int Max = iterationCount;

		for (int elementNumber = iterationCount; elementNumber < elementCount; elementNumber++)
		{
			double expectedMaxValue = Array[Max/mSize][Max%mSize];
			double comparedValue = Array[elementNumber/mSize][elementNumber%mSize];
			if (expectedMaxValue < comparedValue)
			{
				Max = elementNumber;
			}
		}

		if (Max != iterationCount)
		{
			swap(Array[Max/mSize][Max%mSize], Array[iterationCount/mSize][iterationCount%mSize]);
		}
	}
}

void Rotate(int Array[matrixSize][matrixSize], int mSize, int rotateValue) // Короче це якийсь жах, як говорила Олена Віталівна)
{
	/*int next = rotateValue;
	while(Array[0][0] != Array[rotateValue/mSize][rotateValue%mSize])
	{
		int i = 0;
		swap(Array[i/mSize][i%mSize], Array[next/mSize][next%mSize]);
		i++;
		next++;
		if(next = mSize*mSize) next = rotateValue;
		else if(i = rotateValue) rotateValue = next;
	}*/
	int tempArray[matrixSize][matrixSize];
	int j = 0;
	
	for(int i = 0; i < mSize*mSize; i++)
	{
		tempArray[i/mSize][i%mSize] = Array[i/mSize][i%mSize];
	}

	for(int i = 0; i < mSize*mSize; i++)
	{
		if(i + rotateValue < mSize*mSize)
		{
			Array[i/mSize][i%mSize] = Array[(i + rotateValue)/mSize][(i + rotateValue)%mSize];
		}
		else if(i + rotateValue >= mSize*mSize)
		{
			Array[i/mSize][i%mSize] = tempArray[j/mSize][j%mSize];
			j++;
		}
	}
}