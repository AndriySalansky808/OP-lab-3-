#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <numeric>
#include<windows.h>
using namespace std;

string RemoveWordsWithOddConsonants(string input);

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Ukrainian");

    cout << "������ ��������� �����:" << endl;
    string input1;
    getline(cin, input1);

    string lowInput = input1;

    for (size_t i = 0; i < lowInput.length(); ++i)
    {
        lowInput[i] = tolower(lowInput[i]);
    }

    cout << "����� �������� ����:\n" << lowInput << endl;

    vector<string> words;
    size_t startPos = 0, endPos;
    while ((endPos = lowInput.find(' ', startPos)) != string::npos)
    {
        words.push_back(lowInput.substr(startPos, endPos - startPos));
        startPos = endPos + 1;
    }
    words.push_back(lowInput.substr(startPos));

    auto longestWord = max_element(words.begin(), words.end(), [](const string& a, const string& b)
    {
        return a.length() < b.length();
    });
    cout << "�������� �����: " << *longestWord << endl;

    string result = RemoveWordsWithOddConsonants(lowInput);
    cout << "����� ��� ��� � �������� ������� ����������� ����:\n" << result << endl;

    return 0;
}

string RemoveWordsWithOddConsonants(string input) 
{
    size_t startPos = 0, endPos;
    vector<string> words;
    while ((endPos = input.find(' ', startPos)) != string::npos) 
    {
        words.push_back(input.substr(startPos, endPos - startPos));
        startPos = endPos + 1;
    }
    words.push_back(input.substr(startPos));

    const string consonants = "���������������������";
    vector<string> filteredWords;
    copy_if
    (words.begin(), words.end(), back_inserter(filteredWords), [&consonants](const string& word)
        {
        size_t count = count_if(word.begin(), word.end(), [&consonants](char c) 
            {
            return consonants.find(c) != string::npos;
            });
        return count % 2 == 0;
        }
    );

    string result = accumulate
    (filteredWords.begin(), filteredWords.end(), string{}, [](const string& a, const string& b) 
        {
           return a + " " + b;
        }
    );

    return result;
}
