#include <iostream>
#include <cmath>
#include<windows.h>
using namespace std;
int main() 
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "Введіть кількість елементів масиву N: ";
    int N;
    cin >> N;

    double* array = new double[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Введіть " << i + 1 << "-й елемент: ";
        cin >> array[i];
    }

    double minAbsValue = abs(array[0]);
    for (int i = 1; i < N; i++)
    {
        double absValue = abs(array[i]);
        if (absValue < minAbsValue) 
        {
            minAbsValue = absValue;
        }
    }

    cout << "Мінімальний за модулем елемент: " << minAbsValue << endl;

    double sumAfterNegative = 0;
    bool foundNegative = false;

    for (int i = 0; i < N; i++) 
    {
        if (foundNegative) 
        {
            sumAfterNegative += abs(array[i]);
        }
        else if (array[i] < 0)
        {
            foundNegative = true;
        }
    }

    cout << "Сума модулів елементів після першого від'ємного: " << sumAfterNegative << endl;

    cout << "Введіть a: ";
    double a;
    cin >> a;
    cout << "Введіть b: ";
    double b;
    cin >> b;

    int newSize = 0;
    for (int i = 0; i < N; i++) 
    {
        if (array[i] < a || array[i] > b) 
        {
            array[newSize] = array[i];
            newSize++;
        }
    }

    for (int i = newSize; i < N; i++)
    {
        array[i] = 0;
    }

    cout << "Стиснений масив:" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }

    delete[] array;
    return 0;
}
