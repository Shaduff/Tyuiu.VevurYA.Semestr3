// Tyuiu.VevurYA.Semestr3.Lab10.V2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <Windows.h>
#include <algorithm>

using namespace std;

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "������� ����� (��� ����� ����):\n";
    string text;
    getline(cin, text);

    // ������� �� ������ ��� ����� ����������
    for (int i = 0; i < text.size(); i++) {
        if (!isalpha((unsigned char)text[i]) && text[i] != ' ') {
            text.erase(i--, 1);
        }
    }

    // �������������� ��� ����� � ������ �������
    transform(text.begin(), text.end(), text.begin(), ::tolower);

    stringstream ss(text); // ����� ����� ������� ����� ��������� ������ text 
    map<string, int> wordCounts; // ������� ����. ���� ��� �� ���� ��������� �� ������������ �� �����. ������� �� ��� ������ ��� ������� � ������...
    string word;

    while (ss >> word) { // ������ ������ ����� �� ������, ������� � �������.
        wordCounts[word]++;
    }
    cout << "������ ��������� ����:\n";
    for (const auto& pair : wordCounts) {
        cout << pair.first << ": " << pair.second << endl;
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
