// Tyuiu.VevurYA.Semestr3.Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

int getRnd(int min, int max)
{
	return min + rand() % (max - min + 1);
}

void getRndArr(int**& arr, int N, int M, int min, int max)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = getRnd(min, max);
		}
	}
}

void outArr(int** arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
}

void out1dArr(int* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl;
}

void getArr(int** arr, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << "A[" << i << "]" << "[" << j << "] : "; cin >> arr[i][j];
		}
	}
}

void main_diagGet(int** A, int N, int M, int* B)
{
	cout << "Элементы главной диаг.:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == j)
			{
				B[i] = A[i][j];
				cout << setw(4) << "[" << i << "][" << j << "] : " << A[i][j];
			}
		}
	}
	cout << endl;
}

void secnd_diagGet(int** A, int N, int M, int*& B)
{
	cout << "Элементы побочной диаг.:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == M - j - 1)
			{
				B[i] = A[i][j];
				cout << setw(4) << "[" << i << "][" << j << "] : " << A[i][j];
			}
		}
	}
	cout << endl;
}

void diags(int** arr, int N, int M)
{
	int* B = new int[N];
	int* C = new int[N];
	main_diagGet(arr, N, M, B);
	secnd_diagGet(arr, N, M, C);
	cout << "Массив B (Главн.диаг.):\n";
	out1dArr(B, N);
	cout << "Массив C (Побочн.диаг.):\n";
	out1dArr(C, N);
}

int main()
{
	//setlocale(LC_ALL, "Russian");
	setlocale(0, "");
	while (true)
	{
	Start:
		system("CLS");
		cout << "==ВВОД И ВЫВОД МАССИВА V1.0==\n";
		int N, M;
		cout << "Введите границы массива : \nКоличество строк : "; cin >> N;
		cout << "Количество столбцов : "; cin >> M;

		int** A = new int* [N];
		for (int i = 0; i < N; i++)
		{
			A[i] = new int[M];
		}
		cout << "Выделена память под массив " << N << " на " << M << " элементов.\n";


		char qst = ' ';
		cout << "Как вы хотите заполнить массив?\n1 - Случайными числами.\n2 - Вручную.\nВВОД: "; cin >> qst;
		if (qst == '1')
		{
			cout << "==ЗАПОЛНЕНИЕ МАССИВА СЛУЧАЙНЫМИ ЧИСЛАМИ==\n";
			int min, max;
			cout << "Введите диапазон случайных чисел:\n";
			cout << "Введите минимальное случайное значение  : "; cin >> min;
			cout << "Введите максимальное случайное значение : "; cin >> max;
			getRndArr(A, N, M, min, max);
			cout << "Вывод массива " << N << "x" << M << " : \n";
			outArr(A, N, M);
			if (N == M)
			{
				//goto Diags;
				diags(A, N, M);
			}

		}
		else if (qst == '2')
		{
			cout << "==ЗАПОЛНЕНИЕ МАССИВА С КЛАВИАТУРЫ==\n";
			cout << "Введите  значение  элементов : \n";
			getArr(A, N, M);
			cout << "Вывод массива " << N << "x" << M << " : \n";
			outArr(A, N, M);
			if (N == M)
			{
				//goto Diags;
				diags(A, N, M);
			}
		}
		else { cout << "ОШИБКА ВВОДА"; system("pause"); goto Start; }

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
