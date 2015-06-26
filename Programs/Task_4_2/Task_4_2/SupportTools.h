#ifndef SUPPORT_TOOLS_H
#define SUPPORT_TOOLS_H

#define LOC static const char // краще використовувати typedef
static const int matrixSize = 50;

int menu();
void RandomMatrixFilling(int Array[matrixSize][matrixSize], int mSize);
void KeyboardMatrixFilling(int Array[matrixSize][matrixSize], int mSize);
void PrintMatrix(int Array[matrixSize][matrixSize], int mSize);
void ZeroingMatrix(int Array[matrixSize][matrixSize], int mSize);
void SelectionSort(int Array[matrixSize][matrixSize], int mSize);
void Rotate(int Array[matrixSize][matrixSize], int mSize, int rotateValue);

#endif