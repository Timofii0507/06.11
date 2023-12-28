#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void addRowAtIndex(int**& array, int& numRows, int numCols, int* newRow, int index) 
{
    numRows++;
    int** newArray = new int* [numRows];
    for (int i = 0; i < index; ++i)
    {
        newArray[i] = new int[numCols];
        for (int j = 0; j < numCols; ++j) 
        {
            newArray[i][j] = array[i][j];
        }
    }
    newArray[index] = new int[numCols];
    for (int j = 0; j < numCols; ++j) 
    {
        newArray[index][j] = newRow[j];
    }
    for (int i = index + 1; i < numRows; ++i) 
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
    cout << "Початковий масив:" << endl;
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
    int index;
    cout << "Введіть новий рядок розмірністю " << newCols << ":" << endl;
    for (int j = 0; j < newCols; ++j) 
    {
        cout << "Елемент " << j + 1 << ": ";
        cin >> newRow[j];
    }
    cout << "Введіть індекс рядка, куди вставити новий рядок: ";
    cin >> index;
    if (index < 0 || index > numRows)
    {
        cout << "Некоректний індекс. Вставка буде здійснена на початок." << endl;
        index = 0;
    }
    addRowAtIndex(myArray, numRows, numCols, newRow, index);
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
    delete[] newRow;
    return 0;
}