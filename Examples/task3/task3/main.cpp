#include <cstdio>

#define USE_FIRST_RESOLVE
#define USE_DEBUGGING_VALUE

typedef enum 
{
	kBubbleSort,
	kInsertionSort
} SortingType;

static const SortingType kCurrentSortingType = kInsertionSort;
static const int maxMatrixSize = 25;

int main()
{
	// Setup default value for debugging
	double matrix[maxMatrixSize][maxMatrixSize] = {{30, 32, -10, 0, 5},
			    								   {67, -32, -11, -20, 80},
												   {-76, 22, 16, 3, 53},
												   {39, 32, 50, -63, -27},
												   {-43, 42, 10, 2, -29}};
	int matrixSize = 5;
	double numberValue = 0;

#ifndef USE_DEBUGGING_VALUE
	printf("Input matrix size n*n(value between 1 and 25):\n");
	printf("n = ");
	scanf("%i", &matrixSize);
	if (matrixSize < 1 || matrixSize > maxMatrixSize) 
	{
		printf("Wrong input value for matrix size");
		return -1;
	}

	printf("\nInput matrix:\n");
	for (int row = 0; row < matrixSize; row++)
	{
		for (int column = 0; column < matrixSize; column++)
		{
			printf("matrix[%i, %i] = ", row + 1, column + 1);
			scanf("%lf", &numberValue);
			matrix[row][column] = numberValue;
		}
	}
#endif

	// Printing all element that value is less then inputed value
	printf("\nInput limit number:\n");
	printf("N = ");
	scanf("%lf", &numberValue);
	for (int row = 0; row < matrixSize; row++)
	{
		for (int column = 0; column < matrixSize; column++)
		{
			if (matrix[row][column] < numberValue)
				printf("element[%i,%i]=%0.2lf;\n", row + 1, column + 1, matrix[row][column]);
		}
	}

	// Outputing not sorted matrix
	printf("\nGiven matrix:\n");
	for (int row = 0; row < matrixSize; row++)
	{
		printf("[");
		for (int column = 0; column < matrixSize; column++)
		{
			printf("%0.2lf", matrix[row][column]);
			if (column < matrixSize - 1)
				printf(" ");
		}	
		printf("]\n");
	}

#ifdef USE_FIRST_RESOLVE
	// Sorting matrix without using second matrix
	switch (kCurrentSortingType)
	{
		case kBubbleSort:
		{
			for (int iterationCount = 0; iterationCount < matrixSize*matrixSize - 1; iterationCount++)
			{
				for (int elementIndex = iterationCount; elementIndex < matrixSize*matrixSize; elementIndex++)
				{
					double startIterationElement = matrix[iterationCount/matrixSize][iterationCount%matrixSize];
					double currentIterationElement = matrix[elementIndex/matrixSize][elementIndex%matrixSize];
					if (startIterationElement < currentIterationElement) 
					{
						// Swaping elements value
						matrix[iterationCount/matrixSize][iterationCount%matrixSize] = currentIterationElement;
						matrix[elementIndex/matrixSize][elementIndex%matrixSize] = startIterationElement;
					}
				}
			}
			break;
		}
		case kInsertionSort:
		{
			int elementsCount = matrixSize*matrixSize;
			for (int iterationCount = 1; iterationCount < elementsCount; iterationCount++)
			{
				for (int elementIndex = iterationCount; elementIndex > 0; elementIndex--)
				{
					double previouseIterationElement = matrix[(elementIndex - 1)/matrixSize][(elementIndex - 1)%matrixSize];
					double currentIterationElement = matrix[elementIndex/matrixSize][elementIndex%matrixSize];
					if (previouseIterationElement > currentIterationElement)
					{
						// Swaping elements value
						matrix[(elementIndex - 1)/matrixSize][(elementIndex - 1)%matrixSize] = currentIterationElement;
						matrix[elementIndex/matrixSize][elementIndex%matrixSize] = previouseIterationElement;
					}
					else 
					{
						continue;
					}
				}
			}
			break;
		}
		default:
			break;
	}
#else
	// The second resolve is more simple for undestanding,
	// but it require more CPU time and memory
	int linearMatrixSize = matrixSize*matrixSize;
	double tempMatrix[maxMatrixSize*maxMatrixSize];

	// Make copy from original matrix to linear matrix
	int index = 0;
	for (int row = 0; row < matrixSize; row++)
	{
		for (int column = 0; column < matrixSize; column++, index++)
		{
			tempMatrix[index] = matrix[row][column];
		}
	}

	// Make sorting with 'selection sort'
	double maxValue = 0;
	int indexOfMaxValue = 0;
	for (int iterationCount = 0; iterationCount < linearMatrixSize - 1; iterationCount++)
	{
		maxValue = tempMatrix[iterationCount];
		indexOfMaxValue = iterationCount;
		for (int elementIndex = iterationCount + 1; elementIndex < linearMatrixSize; elementIndex++)
		{
			if (maxValue < tempMatrix[elementIndex])
			{
				maxValue = tempMatrix[elementIndex];
				indexOfMaxValue = elementIndex;
			}
		}
		tempMatrix[indexOfMaxValue] = tempMatrix[iterationCount];
		tempMatrix[iterationCount] = maxValue;
	}

	// Make copy to original matrix
	index = 0;
	for (int row = 0; row < matrixSize; row++)
	{
		for (int column = 0; column < matrixSize; column++, index++)
		{
			matrix[row][column] = tempMatrix[index];
		}
	}
#endif

	// Printing sorted matrix
	printf("\nSorted matrix:\n");
	for (int row = 0; row < matrixSize; row++)
	{
		printf("[");
		for (int column = 0; column < matrixSize; column++)
		{
			printf("%0.2lf", matrix[row][column]);
			if (column < matrixSize - 1)
				printf(" ");
		}	
		printf("]\n");
	}

	//Optional part
	printf("\nInput number for search:\n");
	printf("X = ");
	scanf("%lf", &numberValue);
	int foundRow = -1;
	int foundColumn = -1;

//#ifdef USE_FIRST_RESOLVE
	int currentRow, currentColomn;
	int leftLimit = 0, rightLimit = matrixSize*matrixSize - 1;
	while (leftLimit <= rightLimit)
	{
		int middleValue = (leftLimit + rightLimit) / 2;
		currentRow = middleValue / matrixSize;
		currentColomn = middleValue % matrixSize;
		double numberValueInMiddleInterval = matrix[currentRow][currentColomn];
		if (numberValueInMiddleInterval == numberValue)
		{ 
			foundRow = currentRow;
			foundColumn = currentColomn;
			break;
		}
		else if (numberValueInMiddleInterval < numberValue) 
		{
			rightLimit = middleValue - 1;
		}
		else
		{
			leftLimit = middleValue + 1;
		}
	}
//#else
	// Here we can implement binary searching with lenear matrix and return results,
	// but the implementation will be almost no different from the previous,
	// so try write it yourself
//#endif

	if (-1 != foundRow && -1 != foundColumn) {
		printf("Required number is in position [%i, %i]\n", foundRow + 1, foundColumn + 1);
	}
	else {
		printf("There is no required number!\n");
	}

	return 0;
}