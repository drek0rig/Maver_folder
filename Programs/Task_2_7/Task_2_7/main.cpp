#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// �������� ������� ����������
	double sideA, sideB, sideC;

	cout << "Enter side A of triangle: " ;
	cin >> sideA;
	
	cout << "\nEnter side B of triangle: " ;
	cin >> sideB;
		
	cout << "\nEnter side C of triangle: " ;
	cin >> sideC;
		
	if ( (sideA + sideB) > sideC && (sideA + sideC) > sideB && (sideC + sideB) > sideA) // �������� ����� ��������� ����������
	{
		if (sideA == sideB || sideA == sideC || sideC == sideB)		// �������� �� �������������
		{
			if (sideA == sideB && sideB == sideC)					// �������� �� ����������
				{
					cout << "This is equilateral triangle." << endl;
				}												// ������ �������: �� ����� �� ����� �� ����� ���� ��� �� �������� ������� ��������
			else cout << "This is isosceles triangle." << endl;
		}
		else 
			cout << "This is simple triangle." << endl;
	}
	else
		cout << "Triangle is no exist." << endl;

	return 0;
}