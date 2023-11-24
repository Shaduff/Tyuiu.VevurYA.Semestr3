// Tyuiu.VevurYA.Semestr3.Lab8.V4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using  namespace std;

class Integer
{
public:
    Integer(int number)
    {
        value = number;
    }
    void print() const
    {
        cout << "Value: " << value << endl;
    }

    int Compare(Integer ob)
    {
        if (value == ob.value)
        {
            return 0;
        }
        else if (value < ob.value)
        {
            return 1;
        }
        else if (value > ob.value)
        {
            return -1;
        }
    }

private:
    int value;
};


int main()
{
    setlocale(0, "");
    Integer a(6); cout << "Объект a: "; a.print();
    Integer b(5); cout << "Объект b: "; b.print();
    Integer c(5); cout << "Объект c: "; c.print();
    cout << endl;
    
    cout << "Сравнение 'a' и 'b': " << a.Compare(b) << endl;
    cout << "Сравнение 'b' и 'a': " << b.Compare(a) << endl;
    cout << "Сравнение 'b' и 'c': " << b.Compare(c) << endl;
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
