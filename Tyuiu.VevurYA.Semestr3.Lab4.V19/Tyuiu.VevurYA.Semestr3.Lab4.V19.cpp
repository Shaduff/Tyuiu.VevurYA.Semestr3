// Tyuiu.VevurYA.Semestr3.Lab4.V19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <istream>
#include <fstream>
//#include <format>
#include <Windows.h>
#define SIZE 255

using namespace std;

class String
{
	char* str;
	char* str_return;

public:
	String();
	String(char*);
	~String();

	char* Run();
	void Set(char*);
	void Fout();
	int CharCount();

	friend void print(String&);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
	String& operator= (const String& s);
	friend char* Run(String&);
};

String::String()
{
	str = new char[SIZE];
	str[0] = '\0';
	str_return = new char[SIZE];
	str_return[0] = '\0';
};

String::String(char* s)
{
	str = new char[SIZE];
	strcpy(str, s);
	/*
	for (int i = 0; i < strlen(s); i++)
	{
		str[i] = s[i];

	}
	str[strlen(s)] = '\0';
	*/
	str_return = new char[SIZE];
	str_return[0] = '\0';
};

String::~String()
{
	delete[] str;
	cout << "...destructor has been called" << endl;
};

void String::Set(char* s)
{
	for (unsigned int i = 0; i < strlen(s); i++)
	{
		str[i] = s[i];
		str[i] = '\0';
	}
}

void String::Fout()
{
	fstream fout("Output.txt", ios::out);
	if (!fout)
	{
		cout << "[ОШИБКА]: Поток вывода в файл не был запущен.\n";
	}
	else
	{
		fout << str << endl << str_return << endl;
	}
	fout.close();
}

int String::CharCount()
{
	return strlen(str);
}




char* String::Run()
{
	int j = 0;
	bool flag = false;
	 
	if (strlen(str) % 2 == 0)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (flag)
			{
				str_return[j] = str[i];
				j++;
			}
			if (str[i] == ' ') { flag = true; }
		}
		str_return[j] = '\0';
	}
	else strcpy(str_return, str);
	
	return str_return;
}


char* Run(String& obj) { return obj.Run(); }
void print(String& obj) { cout << obj.str << " " << obj.str_return << endl; }
void Fout(String& obj) { return obj.Fout(); }
int CharCount(String& obj) { return obj.CharCount(); }

ostream& operator << (ostream& stream, String& ob)
{
	stream << ob.str;
	return stream;
}

istream& operator >> (istream& stream, String& ob)
{
	stream >> ob.str;
	return stream;
}

String& String::operator=(const String& s)
{
	if (this != &s)
	{
		String temp(s);
		swap(*this, temp);
	}
	return *this;
}




int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s[256];
	while (true)
	{
		system("CLS");
		cout << "Введите что-нибудь и нажмите \"Enter\": " << endl;
		//cin.ignore();
		cin.getline(s, 256);
		String str(s);
		cout << "Вы ввели: " << endl;
		print(str);
		cout << "Количество символов в строке : " << CharCount(str) << " - " << ((CharCount(str) % 2 == 0) ? "четное" : "нечетное")<< endl;
		cout << "Выходная строка: " << endl;
		cout << Run(str) << endl;
		Fout(str);
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
