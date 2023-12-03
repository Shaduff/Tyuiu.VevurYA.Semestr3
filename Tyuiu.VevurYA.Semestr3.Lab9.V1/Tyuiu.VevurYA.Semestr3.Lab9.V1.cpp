// Tyuiu.VevurYA.Semestr3.Lab9.V1.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

    virtual void makeSound() = 0;
};


class Cat : public Animal
{
public:
    Cat(string _name, int _weight)
        : Animal(_name, _weight)
    {}

    virtual void makeSound() override
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

    virtual void makeSound() override
    {
        cout << "Гав." << endl;
    }
};

int main()
{
    setlocale(0, "");
    Cat Barsik("Барсик", 7);
    Barsik.print();
    Barsik.makeSound();
    cout << endl;

    Cat Floppa("Шлёпа", 14);
    Floppa.print();
    Floppa.makeSound();
    cout << endl;

    Dog Sharik("Шарик", 10);
    Sharik.print();
    Sharik.makeSound();
    cout << endl;

    Dog Bobik("Бобик", 12);
    Bobik.print();
    Bobik.makeSound();
    cout << endl;

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
