// Tyuiu.VevurYA.Semestr3.Lab5.V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Базовый класс 
class X
{
protected:
    int* x1;
    int* x2;

public :
    X();
    X(int _x1, int _x2);
    ~X();
    virtual void print();
    virtual void set();
};

// Производный класс 
class Y : public X
{
private :
    int* y;

public:
    Y();
    Y(int _x1, int _x2, int _y);
    ~Y();
    virtual void print() override;
    virtual void set() override;
    virtual void Run_V2_2();
    virtual void Run_V2_9();
    virtual void Run_V2_10();
};


X::X()
{
    x1 = new int;
    x2 = new int;
}

X::X(int _x1, int _x2)
{
    x1 = new int;
    *x1 = _x1;
    x2 = new int;
    *x2 = _x2;
}

X::~X()
{
    delete x1;
    delete x2;
}

void X::print()
{
    cout << "Значения полей класса:\n";
    cout << "x1 = " << *x1 << "\nx2 = " << *x2 << endl;
}

void X::set()
{
    cout << "Введите x1: "; cin >> *x1;
    cout << "Введите x2: "; cin >> *x2;
}


Y::Y()
{
    y = new int;
}

Y::Y(int _x1, int _x2, int _y)
{
    y = new int;
    *y = _y;
}


Y::~Y()
{
    delete y;
}

void Y::print()
{
    cout << "Значения полей класса:\n";
    cout << "x1 = " << *x1 << "\nx2 = " << *x2 << "\ny =  " << *y << endl;
}

void Y::set()
{
    cout << "Введите x1: "; cin >> *x1;
    cout << "Введите x2: "; cin >> *x2;
    cout << "Введите y: "; cin >> *y;
}

void Y::Run_V2_2()
{
    cout << "Задание 2 :  " << *x1 << " * " << *x2 << " * " << *y  << " = " << (*x1 * (*x2) * (*y)) << endl;
}

void Y::Run_V2_9()
{
    cout << "Задание 9 :  (" << *x1 << ")^2 * (" << *x2 << ")^2 * (" << *y << ")^2 =  " << (pow(*x1,2) * pow(*x2, 2 ) * pow(*y,2)) << endl;
}

void Y::Run_V2_10()
{
    cout << "Задание 10 : " << *x1 << " * " << *x2 << " + " << *y << " =  " << ((*x1) * (*x2) + (*y)) << endl;
}


int main()
{
    setlocale(0, "");
    cout << "Создание объекта базового класса...\n";
    X* t;
    cout << "Объект создан.\n";
    t = new X();
    t->set();
    t->print();
    cout << "Объект удалён.\n";
    delete t;

    cout << "Создание объекта производного класса...\n";
    t = new Y();
    cout << "Объект создан\n";
    t->set();
    t->print();
    cout << "Вариант 2:\n";
    ((Y*)t)->Run_V2_2();
    ((Y*)t)->Run_V2_9();
    ((Y*)t)->Run_V2_10();
    
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


