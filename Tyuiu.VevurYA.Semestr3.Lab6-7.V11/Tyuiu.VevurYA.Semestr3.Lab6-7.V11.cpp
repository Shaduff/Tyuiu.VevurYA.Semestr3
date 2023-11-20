// Tyuiu.VevurYA.Semestr3.Lab6-7.V11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

class Specs
{
protected:
    string* type;
    string* model;
    double *frequency;
    int *memorySize;
public:
    Specs()
    {
        type = new string;
        model = new string;
        frequency = new double;
        memorySize = new int;
    }

    Specs(string _type, string _model, double _frequency, int _memorySize)
    {
        type = new string(_type);
        model = new string(_model);
        frequency = new double(_frequency);
        memorySize = new int(_memorySize);
    }

    ~Specs()
    {
        delete type, frequency, memorySize;
    }

    virtual void print() = 0;
};

class Pricing
{
protected:
    double *price;
    int* quantity;
public:
    Pricing()
    {
        price = new double;
        quantity = new int;
    }

    Pricing(double _price, int _quantity)
    {
        price = new double(_price);
        quantity = new int(_quantity);
    }

    ~Pricing()
    {
        delete price, quantity;
    }

    virtual void print() = 0;
};

class Hardware : public Specs, Pricing
{
private:
    string *name;
public:
    Hardware() : Specs(), Pricing()
    {
        name = new string;
    }

    Hardware(string _name, string _type, string _model, double _frequency, int _memorySize, double _price, int _quantity) 
        : Specs(_type, _model, _frequency, _memorySize), Pricing(_price, _quantity)
    {
        name = new string;
    }

    ~Hardware()
    {
        delete name;
    }

    virtual void print() override
    {
        cout << "Наименование:\t" << *name << endl;
        cout << "Тип:\t" << *type << endl;
        cout << "Модель:\t" << *model << endl;
        cout << "Частота:\t" << *frequency << " GHz" << endl;
        cout << "Объем памяти:\t" << *memorySize << " Gb" << endl;
        cout << "Цена:\t" << *price << " руб." << endl;
        cout << "Количество:\t" << *quantity << " ед." << endl;
    }

    double Run()
    {
        return *price * *quantity;
    }

    friend istream& operator>>(istream& in, Hardware& hardware);
    friend ostream& operator<<(ostream& out, Hardware& hardware);
    friend ofstream& operator<<(ofstream& fout, Hardware& hardware);

};

istream& operator>>(istream& in, Hardware& hardware)
{
    cout << "Введите наименование: ";
    in >> *hardware.name;
    cout << "Введите тип: ";
    in.ignore();
    getline(in, *hardware.type);
    cout << "Введите модель: ";
    getline(in, *hardware.model);
    cout << "Введите частоту: ";
    in >> *hardware.frequency;
    cout << "Введите объем памяти: ";
    in >> *hardware.memorySize;
    cout << "Введите цену за шт. : ";
    in >> *hardware.price;
    cout << "Введите количество :";
    in >> *hardware.quantity;
    return in;
}

ostream& operator<<(ostream& out, Hardware& hardware)
{
    out << "Наименование: " << *hardware.name << endl;
    out << "Тип: " << *hardware.type << endl;
    out << "Модель: " << *hardware.model << endl;
    out << "Частота: " << *hardware.frequency << " GHz." << endl;
    out << "Объем памяти: " << *hardware.memorySize << " Gb." << endl;
    out << "Цена: " << *hardware.price << " руб." << endl;
    out << "Количество: " << *hardware.quantity << " ед." << endl;
    out << "Стоимость коплектующих: " << hardware.Run() << " руб." << endl;
    return out;
}

ofstream& operator<<(ofstream& fout, Hardware& hardware)
{
    fout << "Наименование: " << *hardware.name << endl;
    fout << "Тип: " << *hardware.type << endl;
    fout << "Модель: " << *hardware.model << endl;
    fout << "Частота: " << *hardware.frequency << " GHz." << endl;
    fout << "Объем памяти: " << *hardware.memorySize << " Gb." << endl;
    fout << "Цена: " << *hardware.price << " руб." << endl;
    fout << "Количество: " << *hardware.quantity << " ед." << endl;
    fout << "Стоимость коплектующих: " << hardware.Run() << " руб." << endl;
    return fout;
}





int main()
{
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try
    {
        Hardware* hardware = new Hardware;
        cin >> *hardware;
        cout << "Информация о введенных комплекующих:\n";
        cout << endl << *hardware;
        //cout << "Print method:\n"; hardware->print();
        fstream fout("output.txt", ios::out);
        if (!fout)
        {
            throw runtime_error("Ошибка открытия файла.");
        }
        else
        {
            fout << *hardware;
        }
    }
    catch(const exception & e)
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


