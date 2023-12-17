// Tyuiu.VevurYA.Semestr3.Lab10.V4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <Windows.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Введите текст (или набор слов):\n";
    string text;
    getline(cin, text);

    for (int i = 0; i < text.size(); i++) {
        if (!isalpha((unsigned char)text[i]) && text[i] != ' ') {
            text.erase(i--, 1);
        }
    }
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    vector<string> strings;
    stringstream ss(text);
    string word;
    int i = 0;
    while (ss >> word)
    {
        strings.push_back(word);;
        i++;
    }
    cout << "\nВведите символ: ";
    char letter;
    cin >> letter;

    int count = [](const vector<string>& vec, char letter) {
        int counter = 0;
        for (const string& str : vec) {
            if (str.front() == letter) {
                counter++;
            }
        }
        return counter;
    }(strings, letter);

    cout << "Количество слов начинающихся с буквы '" << letter << "': " << count << endl;

    return 0;
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
