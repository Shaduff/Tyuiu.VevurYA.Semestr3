// Tyuiu.VevurYA.Semestr3.Lab2.V19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int getRnd(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void getRndArr(int*& arr, int N, int a, int b)
{
    for (int i = 0; i < N; i++)
    {
        arr[i] = getRnd(a, b);
    }
}

int divby3Count(int* arr, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] % 3 == 0 && abs(arr[i]) >= 3 || arr[i] == 0) count++;
    }
    return count;
}

void outArray(int* arr, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    while (true)
    {
        system("CLS");
        const int N = 5;
        int* A = new int[N];
        int* B = new int[N];

        getRndArr(A, N, -10, 10);
        getRndArr(B, N, -10, 10);

        int Acount = divby3Count(A, N);
        int Bcount = divby3Count(B, N);

        cout << "A neg. count: " << Acount << endl << "B neg. count: " << Bcount << endl;
        if (Acount > Bcount)
        {
            cout << "A : ";  outArray(A, N);
            cout << "B : "; outArray(B, N);
        }
        else
        {
            cout << "B : "; outArray(B, N);
            cout << "A : "; outArray(A, N);
        }
        delete[N] A;
        delete[N] B;
        system("pause");
    }
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
