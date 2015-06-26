// Таск 4.1 з меню.
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <cstring>

using namespace std;

static const int matrixSize = 50;

int menu();
int FirstSubmenu();
void RandomMatrixFilling(int Array[matrixSize][matrixSize], int mSize);
void KeyboardMatrixFilling(int Array[matrixSize][matrixSize], int mSize);
void printMatrix(int Array[matrixSize][matrixSize], int mSize);
void zeroingMatrix(int Array[matrixSize][matrixSize], int mSize);
void selectionSort(int Array[matrixSize][matrixSize], int mSize);
void rot_tate(int Array[matrixSize][matrixSize], int mSize, int rotateValue);

int main()
{
	int Mass[matrixSize][matrixSize] = {(24, -11, 74, 3, -12),
		(97, 7, -41, 31, 2),
		(-1, -38, -59, 73, -3),
		(4, -5, 42, 13, 11),
		(55, 26, -8, -3, 77)}; 

	/*int Mass[matrixSize] = {24, -11, 74, 3, -12, 97, 7, -41, 31, 2}; */
	int mSize = 5;
	int rot = 0;
	char y[] = "y", Y[] = "Y", Yes[] = "Yes", n[] = "n", N[] = "N", No[] = "No";
	char answer[10];

	bool exit = false;
	for(;;)
	{
		int choise = menu();
		switch(choise)
		{
		case (1):
			{
				bool subQuit = false;

				for(;;)
				{
					int subChoise = FirstSubmenu();
					switch(subChoise)
					{
					case (1):
						subQuit = true;
						RandomMatrixFilling(Mass, mSize);
						break;
					case (2):
						subQuit = true;
						printf("Enter a size of the Array:");
						scanf("%d", &mSize);
						printf("\n");
						KeyboardMatrixFilling(Mass, mSize);
						break;
					default:
						printf("Such menu is not exist! Please select again.\n");
						break;
					}

					if(subQuit){
						break;}
				}
				break;
			}
		case (2):
			printMatrix(Mass, mSize);
			break;
		case (3):
			zeroingMatrix(Mass, mSize);
			break;
		case (4):
			selectionSort(Mass, mSize);
			break;
		case (5):
			{
				printf("Enter a shift value (positiv to left shifting and negativ to right shifting):");
				scanf("%d", &rot);
				if(rot >= 0)
				{
					int rotateValue = rot % (mSize * mSize);
					rot_tate(Mass, mSize, rotateValue);
				}
				else
				{
					int rotateValue = mSize + rot % (mSize*mSize);
					rot_tate(Mass, mSize, rotateValue);
				}
				break;
			}
		case (6):
			printf("Are you sure? Tipe Y/y/Yes for exit program and N/n/No for bake to menu:");
			scanf("%s", &answer);
			if(strcmp(answer, Y) == 0 || strcmp(answer, y) == 0 || strcmp(answer, Yes) == 0)
			{
				exit = true;
			}
			break;
		default:
			printf("Such menu is not exist! Please select again.\n");
			break;
		}

		if(exit) // Перевірка умови виходу з нескінченного циклу
		{
			break;
		}
	}

	return 0;
}

int menu()  // Функція виводу основного меню
{
	int choise;

	printf("* * Menu * *\n");
	printf("(1) Input values of matrix elements.\n");
	printf("(2) Output a matrix to the screen.\n");
	printf("(3) Zeroing matrix.\n");
	printf("(4) Sort.\n");
	printf("(5) Perform cyclic shift elements.\n");
	printf("(6) Exit.\n\n");
	printf(":");
	scanf("%d", &choise);

	return choise;
}

int FirstSubmenu() // Функція підменю заповнення матриці
{
	int subChiose;

	printf("(1) Random filling.\n");
	printf("(2) Filling from the keyboard.\n");
	printf("::");
	scanf("%d", &subChiose);

	return subChiose;
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

void printMatrix(int Array[matrixSize][matrixSize], int mSize)	// Друк матриці
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

void zeroingMatrix(int Array[matrixSize][matrixSize], int mSize)	// Занулення матриці
{
	for(int i = 0; i < mSize; i++)
	{
		for(int j = 0; j < mSize; j++)
		{
			Array[i][j] = 0;
		}
	}	
}

void selectionSort(int Array[matrixSize][matrixSize], int mSize)	// Сортування вибором
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

void rot_tate(int Array[matrixSize][matrixSize], int mSize, int rotateValue)
{
	int next = rotateValue;
	while(Array[0][0] != Array[rotateValue/mSize][rotateValue%mSize])
	{
		int i = 0;
		swap(Array[i/mSize][i%mSize], Array[next/mSize][next%mSize]);
		i++;
		next++;
		if(next = mSize*mSize) next = rotateValue;
		else if(i = rotateValue) rotateValue = next;
	}
}