// Tyuiu.VevurYA.Semestr3.Lab8.V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Integer
{
private :
	int* value;
public:
	Integer()
	{
		value = new int;
		cout << "Создан объект класса Integer." << endl;
	}

	~Integer()
	{
		delete value;
		cout << "Объект удалён." << endl;
	}

	// Функция установки значения 
	void set(int _value)
	{
		*value = _value;
	}

	// Функция для печати значения
	void  print()
	{
		cout << *value;
	}

	// Определил дружественную функцию для ввода значения 
	// в поток ввода.
	friend istream& operator>> (istream& in, Integer& ob)
	{
		in >> *ob.value;
		return in;
	}

	// Определил дружественную функцию для вывода значения
	// в поток вывода.
	friend ostream& operator<< (ostream& out, Integer& ob)
	{
		out << *ob.value;
		return out;
	}
};


int main()
{
	setlocale(0, "");
	Integer a;
	Integer b;
	a.set(5);
	cout << "Значение переменной a: "; 
	a.print(); 
	cout << endl;
	cout << "Введите значение переменной b: "; cin >> b;
	cout << "Значение переменной b: " << b << endl;
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
