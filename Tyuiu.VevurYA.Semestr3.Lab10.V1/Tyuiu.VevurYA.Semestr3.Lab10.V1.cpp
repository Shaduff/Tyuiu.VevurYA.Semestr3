// Tyuiu.VevurYA.Semestr3.Lab10.V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <span>
#include <Windows.h>
using namespace std;

class Group
{
public:
	string name;
	double score;
	Group() 
	{
		name = "";
		score = 0;
	}
	Group(string _name, double _score)
	{
		name = _name;
		score = _score;
	}

	friend istream& operator>> (istream& in, Group& ob)
	{
		cout << "Введите имя студента: ";
		in.ignore();
		getline(in, ob.name);
		score_input:
		cout << "Введите балл студента: ";
		in >> ob.score;
		try
		{
			if (in.fail())
			{
				cout << "[Ошибка ввода]: введено не число." << endl;
				in.clear();
				in.ignore();
				goto score_input;
			}
		}
		catch (const exception& e)
		{
			cerr << e.what() << endl;
		}
		return in;
	}

	friend ostream& operator<< (ostream& out, Group& ob)
	{
		out << "Имя студента:\t" << ob.name << endl;
		out << "Балл студента:\t" << ob.score << endl;;
		return out;
	}
};

void groupIn(span<Group> grp)
{
	for (int i = 0; i < grp.size(); i++)
	{
		cout << "Введите студента [" << i + 1 << "]:\n";
		cin >> grp[i];
		cout << endl;
	}
}

void groupOut(span<Group> grp)
{
	cout << "Список студентов:\n";
	double sum = 0;
	for (int i = 0; i < grp.size(); i++)
	{
		cout << "Cтудент [" << i + 1 << "]:\n";
		cout << grp[i];
		sum += grp[i].score;
		cout << endl;
	}
	double avg = sum / grp.size();
	cout << endl << "Средний балл по студентам: " << avg << endl;
}

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		system("CLS");
		int N;
		cout << "Введите количество студентов: ";
		cin >> N;

		try
		{
			if (cin.fail())
			{
				cout << "[Ошибка ввода]: введено не число." << endl;
				cin.clear();
				cin.ignore();
				continue;
			}
			vector<Group> students(N);
			groupIn(students);
			groupOut(students);
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
