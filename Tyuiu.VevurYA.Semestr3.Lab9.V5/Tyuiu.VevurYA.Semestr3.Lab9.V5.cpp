// Tyuiu.VevurYA.Semestr3.Lab9.V5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <span>
#include <spanstream>
using namespace std;

void vectorInput(vector<int>& vec)
{
    cout << "Ввод значений вектора:\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Введите элемент [" << i << "]: ";
        cin >> vec[i];
    }
}

void vectorOutput(span<double> ob)
{
    cout << "Вывод значений структуры:\n";
    for (int i = 0; i < ob.size(); i++)
    {
        cout << setw(4) << "[" << i << "]:" << ob[i];
    }
    cout << endl;
}

double avg(span<double> ob)
{
    int sum = 0;
    for (int i = 0; i < ob.size(); i++)
    {
        sum += ob[i];
    }
    return sum / (double)ob.size();
}

// Заполнение вектора случайными числами
void fill(span<double> ob, int a, int b)
{
    for (int i = 0; i < ob.size(); i++)
    {
        ob[i] = (float)(a * 100 + rand() % (b * 100 - a * 100 + 1)) / 100;
    }
}



int main()
{
    srand(time(0));
    setlocale(0, "");
    const int N = 5;

    vector<double> vec(N);
    double arr[N];

    fill(vec, 0, 20);
    cout << "Вектор:\n";
    vectorOutput(vec);
    cout << endl;
    fill(arr, 0, 20);
    cout << "Массив:\n";
    vectorOutput(arr);
    cout << endl;
    cout << "Среднее значение элементов вектора: " << avg(vec) << endl;
    cout << "Среднее значение элементов массива: " << avg(arr) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
