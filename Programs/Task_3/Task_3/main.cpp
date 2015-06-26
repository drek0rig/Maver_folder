# include <stdio.h>
# include <math.h>
# include <cstdlib>
# include <utility>

static const bool keyboardUse = true;
static const bool sortingUse = false;

using namespace std;

int main()
{
	int mas[25][25] = {};


	if (!keyboardUse)
	// Заповнюємо масив випадковими числами
	{
		for (int i = 0; i < 25; i++)
			for (int j = 0; j < 25; j++)
				mas[i][j] = rand();
	}
	else 
	{
	// Зчитуємо елменти масиву з клавіатури - не повторюйте це в домашніх умовах)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				printf ("Enter element %d %d:", i, j);
				int valueOfElement = 0;
				scanf ("%d", &valueOfElement);
				mas[i][j] = valueOfElement;
			}
	}

	// Зчитуємо розмір робочої області
	int rowN = 0, columnN = 0;
	printf("Enter working area.");
	printf("\nEnter number of lines:\t");
	scanf("%d", &rowN);
	printf("Enter number of columns:\t");
	scanf("%d", &columnN);

	// Обмежуюче число
	int limitNum = 0;
	printf("Enter limit number:");
	scanf("%d", &limitNum);
		
	// int numberOfRow = 0, numberOfColumn = 0;
	int valueOfCurrentElement = 0;
	for (int i=0; i<rowN ; i++)
			for (int j=0; j<columnN ; j++)
				if (mas[i][j] < limitNum)
				{
					valueOfCurrentElement = mas[i][j];
					printf ("\nelement[%d, %d] = %d", i, j, valueOfCurrentElement);
				}
			

	// Сортування
	// Перехід до одновимірного масиву
	int m=0;
	int tempMas [25*25] = {};
	for (int i=0; i<rowN ; i++)
		for (int j=0; j<columnN ; j++)
		{
			tempMas[m++] = mas[i][j];
		}

	if (!sortingUse)  //Вибірка
	{
		for (int m=0; m<rowN*columnN ; m++)
		{
			int max = m;
			for (int n=m; n<rowN*columnN; n++)
				if (tempMas[max]<tempMas[n])
					max = n;
			if (max != m)
				swap (tempMas[max], tempMas[m]);
		}
	}
	else  // Бульбашка
	{
		for (int m=0; m<rowN*columnN-1 ; m++)
			for (int n=0; n<rowN*columnN-m-1; n++)
				if (tempMas[n]<tempMas[n+1])
					swap (tempMas[n], tempMas[n+1]);

	}

	// Бінарний пошук
	int binarFoundValue = 0;
	printf ("\nEnter a value for binary search:\t");
	scanf ("%d", &binarFoundValue);
	
	int begin = 0;
	int end = rowN*columnN;
	int mid = 0;

	while (begin < end)
	{
		mid = begin + (end - begin)/2;

		if (binarFoundValue > tempMas[mid])
		{
			end = mid;
		}
		else
		{
			begin = mid + 1;
		}
	} 

	printf ("\nNumber of element: %d", mid);
	int tempValue = tempMas[mid];
	printf ("\nValue of founded element: %d", tempValue);


	// Повернення в двомірний масив
	m=0;
	for (int i=0; i<rowN ; i++)
		for (int j=0; j<columnN ; j++)
		{
			mas[i][j] = tempMas[m++];
		}

	// Бінарний пошук


	// Вивід
	printf("\n");
	for (int i=0; i<rowN; i++)
	{
		for (int j=0; j<columnN; j++)
		{
			int currentValue = mas[i][j];
			printf("%d\t", currentValue);
		}
		printf("\n");
	}
	return 0;
}