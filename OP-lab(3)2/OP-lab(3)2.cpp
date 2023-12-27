#include <iostream>
#include <vector>
#include<windows.h>
using namespace std;
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введіть кількість рядків матриці: ";
    int rows;
    cin >> rows;

    cout << "Введіть кількість стовпців матриці: ";
    int cols;
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << "Введіть елемент [" << i + 1 << "," << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    int columnWithZero = -1;
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++) 
        {
            if (matrix[i][j] == 0)
            {
                columnWithZero = j;
                break;
            }
        }
        if (columnWithZero != -1)
            break;
    }

    if (columnWithZero != -1)
    {
        cout << "перший стовпець із нульовим елементом: " << columnWithZero + 1 << endl;
    }
    else 
    {
        cout << "В матриці немає стовпців із нульовим елементом." << endl;
    }

    vector<int> characteristics(rows);
    for (int i = 0; i < rows; i++)
    {
        int sumOfNegativeEvenElements = 0;
        for (int j = 0; j < cols; j++) 
        {
            if (matrix[i][j] < 0 && matrix[i][j] % 2 == 0)
            {
                sumOfNegativeEvenElements += matrix[i][j];
            }
        }
        characteristics[i] = sumOfNegativeEvenElements;
    }

    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (characteristics[i] > characteristics[j] || (characteristics[i] == characteristics[j] && matrix[i] > matrix[j]))
            {
               
                int tempCharacteristic = characteristics[i];
                characteristics[i] = characteristics[j];
                characteristics[j] = tempCharacteristic;

                
                vector<int> tempRow = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = tempRow;
            }
        }
    }

    cout << "\nВідсортована матриця:" << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}

