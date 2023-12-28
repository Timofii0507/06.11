#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void deleteColumnAtIndex(int**& array, int numRows, int& numCols, int index) 
{
    if (numCols <= 0 || index < 0 || index >= numCols) 
    {
        cout << "Некоректний індекс для видалення стовпця." << endl;
        return;
    }
    int** newArray = new int* [numRows];
    for (int i = 0; i < numRows; ++i) 
    {
        newArray[i] = new int[numCols - 1];
        int colIndex = 0;
        for (int j = 0; j < numCols; ++j) 
        {
            if (j != index) {
                newArray[i][colIndex++] = array[i][j];
            }
        }
    }
    for (int i = 0; i < numRows; ++i) 
    {
        delete[] array[i];
    }
    delete[] array;
    array = newArray;
    numCols--;
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
    int index;
    cout << "Введіть індекс стовпця, який бажаєте видалити: ";
    cin >> index;
    deleteColumnAtIndex(myArray, numRows, numCols, index);
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
