// Tyuiu.VevurYA.Semestr3.Lab8.V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(int number);
    int getValue() const;
    void setValue(int number);
    void print() const;
private:
    int value;
};

Integer::Integer(int number)
{
    value = number;
    cout << "Object created" << endl;
}

int Integer::getValue() const { return value; }

void Integer::setValue(int number) { value = number; }

void Integer::print() const 
{
    cout << "Значение: " << value << endl;
}

int main()
{
    setlocale(0, "");
    const Integer a(5);
    Integer b(7);
    //a.setValue(5); // По логике у константы нельзя поменять значение.
    b.setValue(8);
    cout << "\ngetValue:\n";
    cout << "Значение переменной 'a': " << a.getValue() << endl;
    cout << "Значение переменной 'b': " << b.getValue() << endl;

    cout << "\nPrint:\n";
    a.print();
    b.print();
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
