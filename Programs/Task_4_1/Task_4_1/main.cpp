// Таск 4.1 з меню.
#include <stdio.h>
#include <cstdlib>
#include <ctime>

static const int matrixSize = 50;

int menu();
int FirstSubmenu();
void RandomMatrixFilling(int Array[matrixSize][matrixSize], int mSize);
void KeyboardMatrixFilling(int *Array, int mSize);
void printMatrix(int *Array, int mSize);
void zeroingMatrix(int *Array, int mSize);

int main()
{
	int Mass[matrixSize][matrixSize] = {(24, -11, 74, 3, -12),
										(97, 7, -41, 31, 2),
										(-1, -38, -59, 73, -3),
										(4, -5, 42, 13, 11),
										(55, 26, -8, -3, 77)}; 
	
	/*int Mass[matrixSize] = {24, -11, 74, 3, -12, 97, 7, -41, 31, 2}; */
	int mSize = 10;
	
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
						KeyboardMatrixFilling(&Mass[0], mSize);
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
			printMatrix(&Mass[0], mSize);
			break;
		case (3):
			zeroingMatrix(&Mass[0], mSize);
			break;
		case (4):
			break;
		case (5):
			break;
		case (6):
			exit = true;
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

void KeyboardMatrixFilling(int *Array, int mSize)  // Заповнення матриці з клавіатури
{
	for(int i = 0; i < mSize; i++)
	{
		printf("Enter a value of element[%d]:", i);
		scanf("%d", Array+i);
		printf("\n");
	}
}

void printMatrix(int *Array, int mSize)
{
	for (int i = 0; i < mSize; i++)
	{
		printf("%d\t", *(Array+i));
	}
	printf("\n");
}

void zeroingMatrix(int *Array, int mSize)
{
	for(int i = 0; i < mSize; i++)
	{
		*(Array + i) = 0;
	}	
}