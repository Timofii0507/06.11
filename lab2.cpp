#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void addRowToBeginning(int**& array, int& numRows, int numCols, int* newRow) 
{
    numRows++;
    int** newArray = new int* [numRows];
    newArray[0] = new int[numCols];
    for (int j = 0; j < numCols; ++j) 
    {
        newArray[0][j] = newRow[j];
    }
    for (int i = 1; i < numRows; ++i)
    {
        newArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j)
        {
            newArray[i][j] = array[i - 1][j];
        }
    }
    for (int i = 0; i < numRows - 1; ++i) 
    {
        delete[] array[i];
    }
    delete[] array;
    array = newArray;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(static_cast<unsigned>(time(0)));
    int numRows = 3;
    int numCols = 4;
    int** myArray = new int* [numRows];
    for (int i = 0; i < numRows; ++i) 
    {
        myArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) 
        {
            myArray[i][j] = rand() % 100;
        }
    }
    cout << "���������� �����:" << endl;
    for (int i = 0; i < numRows; ++i) 
    {
        for (int j = 0; j < numCols; ++j) 
        {
            cout << myArray[i][j] << " ";
        }
        cout << endl;
    }
    int newCols = numCols;
    int* newRow = new int[newCols];
    for (int j = 0; j < newCols; ++j) 
    {
        newRow[j] = rand() % 100;
    }
    addRowToBeginning(myArray, numRows, numCols, newRow);
    cout << "��������� �����:" << endl;
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
    delete[] newRow;
    return 0;
}