// Tyuiu.VevurYA.Semestr3.Lab8.V5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Animal
{
protected:
    string name;
    int weight;
public:
    Animal(string _name, int _weight)
    {
        name = _name;
        weight = _weight;
    }

    void print()
    {
        cout << "Информация о животном: " << endl;
        cout << "Имя: " << name << endl;
        cout << "Вес: " << weight << endl;
    }

    virtual void voice() = 0;
};


class Cat : public Animal
{
public:
    Cat(string _name, int _weight)
        : Animal(_name, _weight)
    {}

    virtual void voice() override 
    {
        cout << "Мяу." << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(string _name, int _weight)
        : Animal(_name, _weight)
    {}

    virtual void voice() override
    {
        cout << "Гав." << endl;
    }
};

int main()
{
    setlocale(0, "");
    Cat Barsik("Барсик", 7);
    Barsik.print();
    Barsik.voice();
    
    Cat Floppa("Шлёпа", 14);
    Floppa.print();
    Floppa.voice();

    Dog Sharik("Шарик", 10);
    Sharik.print();
    Sharik.voice();

    Dog Bobik("Бобик", 12);
    Bobik.print();
    Bobik.voice();

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
