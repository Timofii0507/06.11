#include <iostream>
#include <Windows.h>
using namespace std;

void cyclicShift(int**& array, int numRows, int numCols, int shiftRows, int shiftCols, bool shiftRight) 
{
    for (int i = 0; i < numRows; ++i) 
    {
        int* tempRow = new int[numCols];
        for (int j = 0; j < numCols; ++j) 
        {
            int shiftedIndex = (j + (shiftRight ? shiftRows : numCols - shiftRows)) % numCols;
            tempRow[shiftedIndex] = array[i][j];
        }
        delete[] array[i];
        array[i] = tempRow;
    }
    for (int j = 0; j < numCols; ++j) 
    {
        int* tempCol = new int[numRows];
        for (int i = 0; i < numRows; ++i) 
        {
            int shiftedIndex = (i + (shiftRight ? shiftCols : numRows - shiftCols)) % numRows;
            tempCol[shiftedIndex] = array[i][j];
        }
        for (int i = 0; i < numRows; ++i) 
        {
            array[i][j] = tempCol[i];
        }
        delete[] tempCol;
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int numRows = 3;
    int numCols = 4;
    int** myArray = new int* [numRows];
    for (int i = 0; i < numRows; ++i) 
    {
        myArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) 
        {
            myArray[i][j] = i * numCols + j;
        }
    }
    cout << "Початковий масив:" << endl;
    for (int i = 0; i < numRows; ++i) 
    {
        for (int j = 0; j < numCols; ++j)
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
    int shiftRows, shiftCols;
    bool shiftRight;
    cout << "Введіть кількість зсувів для рядків: ";
    cin >> shiftRows;
    cout << "Введіть кількість зсувів для стовпців: ";
    cin >> shiftCols;
    cout << "Введіть напрям зсуву (1 - вправо, 0 - вліво): ";
    cin >> shiftRight;
    cyclicShift(myArray, numRows, numCols, shiftRows, shiftCols, shiftRight);
    cout << "Оновлений масив:" << endl;
    for (int i = 0; i < numRows; ++i) 
    {
        for (int j = 0; j < numCols; ++j)
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < numRows; ++i)
    {
        delete[] myArray[i];
    }
    delete[] myArray;
    return 0;
}
