// Tyuiu.VevurYA.Semestr3.Lab4.V14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// 14. Мобильные телефоны     
// (Наименование, фирма, стандарт связи, заряд аккумулятора, потребление 
// при ожидании, потребление при разговоре, время ожидания - функция Run(),
// время разговора - функция Run1())


#include <iostream>
#include <Windows.h>
using namespace std;

class Branding
{
protected:
    string* name;
    string* brand;
public:
    Branding()
    {
        name = new string;
        brand = new string;
    }
    
    Branding(string _name, string _brand)
    {
        name = new string;
        *name = _name;
        brand = new string;
        *brand = _brand;
    }

    ~Branding()
    {
        delete name, brand;
    }

    virtual void print() = 0;
};


class Specs
{
protected:
    string* comstandart;
    int* batcapacity;
    int* standbyconsumption;
    int* onlineconsumption;
public:
    Specs()
    {
        comstandart = new string;
        batcapacity = new int;
        standbyconsumption = new int;
        onlineconsumption = new int;
    }

    Specs(string _comstandart, int _batcapacity, int _standbyconsumption, int _onlineconsumption)
    {
        comstandart = new string;
        *comstandart = _comstandart;
        batcapacity = new int;
        *batcapacity = _batcapacity;
        standbyconsumption = new int;
        *standbyconsumption = _standbyconsumption;
        onlineconsumption = new int;
        *onlineconsumption = _onlineconsumption;
    }

    ~Specs()
    {
        delete comstandart, batcapacity, standbyconsumption, onlineconsumption;
    }


    virtual void print() = 0;
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
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
