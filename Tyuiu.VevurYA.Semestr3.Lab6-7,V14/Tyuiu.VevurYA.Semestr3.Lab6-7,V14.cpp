// Tyuiu.VevurYA.Semestr3.Lab4.V14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// 14. Мобильные телефоны     
// (Наименование, фирма, стандарт связи, заряд аккумулятора, потребление 
// при ожидании, потребление при разговоре, время ожидания - функция Run(),
// время разговора - функция Run1())


#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
using namespace std;


// класс брендинг
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

// класс характеристики
class Specs
{
protected:
    string* comstandart;    // стандарт связи
    int* batcap;
    int* standbyconsumption;
    int* onlineconsumption;
public:
    Specs()
    {
        comstandart = new string;
        batcap = new int;
        standbyconsumption = new int;
        onlineconsumption = new int;
    }

    Specs(string _comstandart, int _batcap, int _standbyconsumption, int _onlineconsumption)
    {
        comstandart = new string;
        *comstandart = _comstandart;
        batcap = new int;
        *batcap = _batcap;
        standbyconsumption = new int;
        *standbyconsumption = _standbyconsumption;
        onlineconsumption = new int;
        *onlineconsumption = _onlineconsumption;
    }

    ~Specs()
    {
        delete comstandart, batcap, standbyconsumption, onlineconsumption;
    }


    virtual void print() = 0;
};

class Phone : public Branding, Specs
{
public:
    Phone() {};
    Phone(string _name, string _brand, string _comstandart, int _batcap, int _standbyconsumption, int _onlineconsumption)
        :Branding(_name, _brand), Specs(_comstandart, _batcap, _standbyconsumption, _onlineconsumption)
    {};

    virtual void print() override
    {
        cout << "Наименование:\t" << *name << endl;
        cout << "Фирма:\t" << *brand << endl;
        cout << "Стандарт связи:\t" << *comstandart << endl;
        cout << "Объем аккумулятора:\t" << *batcap << "mAh" << endl;
        cout << "Потребление при ожидании:\t" << *standbyconsumption << "mAh" << endl;
        cout << "Потребление при разговоре:\t" << *onlineconsumption << "mAh" << endl;
    }

    double Run()
    {
        return *batcap / *standbyconsumption;
    }

    double Run1()
    {
        return *batcap / *onlineconsumption;
    }


    friend istream& operator>> (istream& in, Phone& phone)
    {
        cout << "Введите наименование: "; 
        in >> *phone.name;
        cout << "Введите фирму: "; 
        in >> *phone.brand;
        cout << "Введите стандарт связи: "; 
        in >> *phone.comstandart;
        cout << "Введите объем аккумулятора: "; 
        in >> *phone.batcap;
        cout << "Введите потребление при ожидании: "; 
        in >> *phone.standbyconsumption;
        cout << "Введите потребление при разговоре: "; 
        in >> *phone.onlineconsumption;
        return in;
    }

    friend ostream& operator<< (ostream& out, Phone& phone)
    {
        out << "Наименование:\t" << *phone.name << endl;
        out << "Фирма:\t" << *phone.brand << endl;
        out << "Стандарт связи:\t" << *phone.comstandart << endl;
        out << "Объем аккумулятора:\t" << *phone.batcap << "mAh" << endl;
        out << "Потребление при ожидании:\t" << *phone.standbyconsumption << "mAh" << endl;
        out << "Потребление при разговоре:\t" << *phone.onlineconsumption << "mAh" << endl;
        return out;
    }

    friend ofstream& operator<< (ofstream& fout, Phone& phone)
    {
        fout << "Наименование:\t" << *phone.name << endl;
        fout << "Фирма:\t" << *phone.brand << endl;
        fout << "Стандарт связи:\t" << *phone.comstandart << endl;
        fout << "Объем аккумулятора:\t" << *phone.batcap << "mAh" << endl;
        fout << "Потребление при ожидании:\t" << *phone.standbyconsumption << "mAh" << endl;
        fout << "Потребление при разговоре:\t" << *phone.onlineconsumption << "mAh" << endl;
        return fout;
    }
};






int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    try {
        Phone* phone = new Phone;
        cin >> *phone;
        cout << "Информация о введенном транспорте: " << endl;
        cout << *phone;
        //cout << "Print method:\n"; transport->print();
        ofstream fout("output.txt", ios::out);
        if (!fout) {
            throw runtime_error("Ошибка открытия файла.");
        }
        else
        {
            fout << *phone;
            fout << "Время ожидания: " << phone->Run() << " ч." << endl;
            fout << "Время разговора: " << phone->Run1() << " ч." << endl;
        }
        cout << "Время ожидания: " << phone->Run() << " ч." << endl;
        cout << "Время разговора: " << phone->Run1() << " ч." << endl;
    }
    catch (const exception& e)
    {
        cerr << "ОШИБКА" << e.what() << endl;
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
