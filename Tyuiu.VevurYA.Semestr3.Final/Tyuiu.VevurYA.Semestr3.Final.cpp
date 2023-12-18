// Tyuiu.VevurYA.Semestr3.Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

class Array
{
private:
    int** arr;
    int M;
    int N;
    int S;
    long P;
    float Avg;

public:
    //стандартный коструктор
    Array()
    {
        N = 7;
        M = 7;
        arr = new int* [N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int[M];
        }
        rnd(1, 9);
        Avg = average();
        S = sum();
        P = prd();
    }
    // конструктор с аргументами
    Array(int _N, int _M, int min, int max)
    {
        N = _N;
        M = _M;
        arr = new int*[N];
        for (int i = 0; i < N; i++)
        {
            arr[i] = new int[M];
        }
        rnd(min, max);
        Avg = average();
        S = sum();
        P = prd();
    }

    ~Array()
    {
        delete[] arr;
    }

    // метод вычисления суммы элементов
    int sum()
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j > M / 2 && i < N / 2)
                {
                    sum += arr[i][j];
                }
                else if (j < M / 2 && i > N / 2)
                {
                    sum += arr[i][j];
                }
            }
        }
        return sum;
    }

    //  метод вычисления произведения элементов
    long prd()
    {
        long prod = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j > M / 2 && i < N / 2)
                {
                    prod *= (long)arr[i][j];
                }
                else if (j < M / 2 && i > N / 2)
                {
                    prod *= (long)arr[i][j];
                }
                //cout << prod << endl;
            }
        }
        return (long)prod;
    }

    // метод вычисления среднегго арифметического элементов
    float average()
    {
        int summ = 0;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j > M / 2 && i < N / 2)
                {
                    summ += arr[i][j];
                    count++;
                }
                else if (j < M / 2 && i > N / 2)
                {
                    summ += arr[i][j];
                    count++;
                }
            }
            //cout << summ << endl;
            //cout << count << endl;
        }
        return summ /(float)count;
    }

    // простой метод вывода массива на консоль
    void print()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j > M / 2 && i < N / 2)
                {
                    cout << "[" << arr[i][j] << "] ";
                }
                else if (j < M / 2 && i > N / 2)
                {
                    cout << "[" << arr[i][j] << "] ";
                }
                else
                {
                    cout << setw(4) << arr[i][j] << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
        cout << "Avg: " << Avg;
        cout << "S: " << S;
        cout << "P: " << P;
    }

    // медот заполнения массива случайными числами
    void rnd(int min, int max)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                arr[i][j] = min + rand() % (max - min + 1);
            }
        }
    }


    // переопределение оператора потока вывода
    friend ostream& operator<< (ostream& out, Array& ob)
    {
        for (int i = 0; i < ob.N; i++)
        {
            for (int j = 0; j < ob.M; j++)
            {
                if (j > ob.M / 2 && i < ob.N / 2)
                {
                    out << setw(2) << "[" << ob.arr[i][j] << "]";
                }
                else if (j < ob.M / 2 && i > ob.N / 2)
                {
                    out << setw(2)<< "[" << ob.arr[i][j] << "]";
                }
                else
                {
                    out << setw(4) << ob.arr[i][j] << "";
                }
            }
            out << endl;
        }
        out << endl;
        out << "Сумма выделеных элементов массива (S): " << ob.S << endl;
        out << "Произведение выделеных элементов массива (P): " << ob.P << endl;
        out << "Среднее арифметическое выделенных элементов массива (Avg): " << ob.Avg << endl;

        return out;
    }
};

// функция "отрисовки" шапки
void headerDrow()
{
    cout << "--------------------------------------------\n";
    cout << "| Итоговая работа  Вевюр Я.А. Вариант [10] |\n";
    cout << "--------------------------------------------\n";
    cout << endl;
}

int main()
{
    setlocale(0, "");
    srand(time(NULL));
    while (true)
    {
        system("CLS");
        headerDrow();
        int N, M;
        cout << "Введите размерность массива:\n\tВведите число строк (N): ";
        cin >> N;
        cout << "\tВведите число столбцов (M): ";
        cin >> M;
        // проверка на ввод НЕ числа
        try {
            if (cin.fail())
            {
                system("CLS");
                headerDrow();
                cout << "[ОШИБКА ВВОДА]: Введено не число." << endl;
                cin.clear();
                cin.ignore();
                system("pause");
                continue;
            }

            Array arr(N, M, 1, 5);
            cout << "Массив:\n\n" << arr << endl;
            system("pause");

        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;
        }
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
