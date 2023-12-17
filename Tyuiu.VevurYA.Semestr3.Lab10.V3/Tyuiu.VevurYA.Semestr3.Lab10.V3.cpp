// Tyuiu.VevurYA.Semestr3.Lab10.V3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "Введите текст (или набор слов):\n";
    string text;
    getline(cin, text);

    cout << "\nВведите символ: ";
    char letter;
    cin >> letter;

    vector<string> words;

    // разбиваем текст на слова и проверяем, начинаются ли они с символа
    string word;
    for (int i = 0; i < text.length()+1; i++) {
        if (isalpha((unsigned char)text[i])) {
            word += text[i];
        }
        else {
            if (!word.empty() && tolower(word[0]) == tolower(letter)) {
                words.push_back(word);
            }
            word.clear();
        }
    }

    cout << "\nСлова начианющиеся с символа '" << letter << "':\n";
    for (const auto& word : words) { 
        cout << word << endl;
    }

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
