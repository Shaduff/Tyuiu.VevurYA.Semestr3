// Tyuiu.VevurYA.Semestr3.Lab4.V9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <istream>
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

	friend void print(String&);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
	friend char* Run(String&);
};

String::String()
{
	str = new char[SIZE];
	str[0] = '\0';
	str_return[0] = '\0';
};

String::String(char* s)
{
	str = new char[SIZE];
	//strncpy(str, s, strlen(s));
	for (int i = 0; i < strlen(s); i++)
	{
		str[i] = s[i];
		if (s[i + 1] == NULL) { break; }
	}
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

char* String::Run()
{
	int j = 0;
	int countS1 = 0;
	int countS2 = 0;
	int countS3 = 0;
	
	if (strlen(str) % 5 == 0)
	{
		for (unsigned int i = 0; i < strlen(str); i++)
		{
			if (str[i] == '{' || str[i] == '}') { countS1++; }
			if( str[i] == '[' || str[i] == ']' ) { countS2++; }
			if( str[i] == '(' || str[i] == ')') { countS3++; }
		}
	}
	
	
	return;
}

char* Run(String& obj) { return obj.Run(); }
void print(String& obj) { cout << obj.str << " " << obj.str_return << endl; }
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



int main()
{
	setlocale(0, "");
	char s[256];
	cin.getline(s, 256);
	String str(s);

	while (true)
	{

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
