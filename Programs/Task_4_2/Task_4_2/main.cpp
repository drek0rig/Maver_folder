#include <stdio.h>
#include <cstring>
#include "SupportTools.h"

using namespace std;

LOC kMatrixSizeRequest[] = "Enter a size of the Array:";
LOC kMenuItemNotExist[] = "Such menu is not exist! Please select again.";
LOC kShiftValueRequest[] = "Enter a shift value (positiv to left shifting and negativ to right shifting):";
LOC kExitConfirmationRequest[] = "Are you sure? Type Y/y/Yes for exit program and N/n/No for back to menu:";

LOC kSubMemuRandomFilling[] = "(1) Random filling.";
LOC kSubMenuKeyboardFilling[] = "(2) Filling from the keyboard.";

int FirstSubmenu();

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
						printf(kMatrixSizeRequest);
						scanf("%d", &mSize);
						printf("\n");
						KeyboardMatrixFilling(Mass, mSize);
						break;
					default:
						printf("%s\n", kMenuItemNotExist);
						break;
					}

					if(subQuit){
						break;}
				}
				break;
			}
		case (2):
			PrintMatrix(Mass, mSize);
			break;
		case (3):
			ZeroingMatrix(Mass, mSize);
			break;
		case (4):
			SelectionSort(Mass, mSize);
			break;
		case (5):
			{
				printf(kShiftValueRequest);
				scanf("%d", &rot);
				if(rot >= 0)
				{
					int rotateValue = rot % (mSize * mSize);
					Rotate(Mass, mSize, rotateValue);
				}
				else
				{
					int rotateValue = mSize*mSize + rot % (mSize*mSize);
					Rotate(Mass, mSize, rotateValue);
				}
				break;
			}
		case (6):
			printf(kExitConfirmationRequest);
			scanf("%s", &answer);
			if(strcmp(answer, Y) == 0 || strcmp(answer, y) == 0 || strcmp(answer, Yes) == 0)
			{
				exit = true;
			}
			break;
		default:
			printf("%s\n", kMenuItemNotExist);
			break;
		}

		if(exit) // Перевірка умови виходу з нескінченного циклу
		{
			break;
		}
	}

	return 0;
}

int FirstSubmenu() // Функція підменю заповнення матриці
{
	int subChiose;

	printf("%s\n", kSubMemuRandomFilling);
	printf("%s\n", kSubMenuKeyboardFilling);
	printf("::");
	scanf("%d", &subChiose);

	return subChiose;
}