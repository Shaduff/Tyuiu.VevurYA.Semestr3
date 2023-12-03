// Tyuiu.VevurYA.Semestr3.Lab9.V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Integer
{
public:
    Integer(double n)
    {
        value = n;
    }

    void print()  const
    {
        cout << "Значение: " << value << endl;
    }

    // определение через метод класса
    void mult(int a)
    {
        value *= a;
    }
    void mult(double a)
    {
        value *= a;
    }

    // определение через friend функцию
    friend Integer operator*= ( Integer& ob, int a)
    {
        ob.value *= a;
        return ob;
    }

    friend Integer operator*= (Integer& ob, double a)
    {
        ob.value *= a;
        return ob;
    }

    friend ostream& operator<< (ostream& out, Integer ob)
    {
        out << ob.value;
        return out;
    }

private:
    double value;
};


int main()
{
    setlocale(0, "");
    Integer a = 2;
    cout << "Объект 'a' = " << a << endl;

    cout << "Объект 'a' * 3 =\n";
    a *= 3;
    a.print();
    cout << endl;

    cout << "Объект 'a' * 2.7 =\n";
    a *= 2.7;
    a.print();
    cout << endl;

    cout << "Объект 'a' * 2 =\n";
    a.mult(2);
    a.print();
    cout << endl;

    cout << "Объект 'a' * 3.8 =\n";
    a.mult(3.8);
    a.print();
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
