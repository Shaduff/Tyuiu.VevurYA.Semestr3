// Tyuiu.VevurYA.Semestr3.Lab9.V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void vectorInput(vector<int> &vec)
{
    cout << "Ввод значений венктора:\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "Введите элемент [" << i << "]: ";
        cin >> vec[i];
    }
}

void vectorOutput(vector<int> vec)
{
    cout << "Вывод значений венктора (в обратном порядке):\n";
    for (int i = vec.size()-1; i >= 0; i--)
    {
        cout << setw(4) <<"["<< i <<"]:" << vec[i];
    }
}

int main()
{
    setlocale(0, "");
    int N;
    cout << "Введите размер вектора: ";
    cin >> N;
    vector<int> vec(N);
    cout << "Создан вектор с размером (" << vec.size() << ")\n";
    vectorInput(vec);
    vectorOutput(vec);
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
