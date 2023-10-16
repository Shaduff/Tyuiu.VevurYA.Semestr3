// Tyuiu.VevurYA.Semestr3.Lab3.V14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "MyClass.h"
using namespace std;


int main()
{
	setlocale(0, "");
	while (true)
	{
		system("CLS");
		double x = 0, y = 0, z = 0;
		char qst = ' ';
		my_Fun Fun1;
		cout << "Какие исходные данные ввести?\n1) Стандартный набор\n2) Пользовательский набор.\nВВОД: "; cin >> qst;
		if (qst == '1')
		{
			x = 2.444;
			y = 0.869;
			z = -0.13;
			cout << "Набор стандартных данных:\nX = " << x << "\nY = " << y << "\nZ = " << z << endl;
			Fun1.set(x, y, z);
		}
		else if (qst == '2')
		{
			cout << "Введите исходные данные:\n";
			cout << "X : "; cin >> x;
			cout << "Y : "; cin >> y;
			cout << "Z : "; cin >> z;
			cout << "Набор введенных данных:\nX = " << x << "\nY = " << y << "\nZ = " << z << endl;
			Fun1.set(x, y, z);
		}
		else
		{
			system("CLS");
			cout << "[ОШИБКА ВВОДА]" << endl;
			system("pause");
			continue;
		}
		Fun1.run();
		cout << "Результат h : ";  
		Fun1.print();
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
