// Tyuiu.VevurYA.Semestr3.Lab9.V4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
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

void vectorOutput(unique_ptr<vector<int>>& vec)
{
    cout << "Вывод значений вектора:\n";
    for (int i = 0; i < (*vec).size(); i++)
    {
        cout << setw(4) << "[" << i << "]:" << (*vec)[i];
    }
    cout << endl;
}

int vectorSumm(unique_ptr<vector<int>>& vec)
{
    int sum = 0;
    for (int i = 0; i < (*vec).size(); i++)
    {
        sum += (*vec)[i];
    }
    return sum;
}

int main()
{
    setlocale(0, "");
    int N;
    cout << "Введите размер вектора: ";
    cin >> N;

    unique_ptr<vector<int>> vec = {make_unique<vector<int>>(N)};

    for (int i = 0; i < N; i++)
    {
        (*vec)[i] = i * i;
    }

    vectorOutput(vec);
    cout <<"Сумма элементов вектора: " << vectorSumm(vec) << endl;
    //vector<int> vec(N);
    //cout << "Создан вектор с размером (" << vec.size() << ")\n";
    //vectorInput(vec);
    //vectorOutput(vec);
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
