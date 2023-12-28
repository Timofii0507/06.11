#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void deleteRowAtIndex(int**& array, int& numRows, int numCols, int index)
{
    if (numRows <= 0 || index < 0 || index >= numRows) 
    {
        cout << "Некоректний індекс. Рядок не може бути видалений." << endl;
        return;
    }
    numRows--;
    int** newArray = new int* [numRows];
    for (int i = 0, j = 0; i < numRows + 1; ++i) 
    {
        if (i != index) 
        {
            newArray[j] = new int[numCols];
            for (int k = 0; k < numCols; ++k) 
            {
                newArray[j][k] = array[i][k];
            }
            j++;
        }
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
    int index;
    cout << "Введіть індекс рядка, який бажаєте видалити: ";
    cin >> index;
    deleteRowAtIndex(myArray, numRows, numCols, index);
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
