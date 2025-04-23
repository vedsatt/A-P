#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

struct substring {
    int parent;
    string str;
};

bool isRuUpper(char c) {
    return (c >= 'А') && (c <= 'Я');
}

bool isLatin(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void inputVector(vector<string>* strings) {
    string input;
    bool flag = true;
    
    cout << "Введите строки (для окончания ввода нажмите ENTER):\n";
    while (flag) {
        getline(cin, input);
        if (input.empty()) {
            flag = false;
        } else {
            strings->push_back(input);
        }
    }

    if (strings->size() == 0) {
        throw logic_error("Массив не может быть пустым");
    } 
}

void findSubstrings(const vector<string>* strings, vector<substring>* substrings) {
    for (int i = 0; i < strings->size(); i++) {
        string str = (*strings)[i];
        int j = 0;
        while (j < str.length()) {
            if (isupper(str[j]) || isRuUpper(str[j])) {
                while ((isupper(str[j]) || isRuUpper(str[j])) && j < str.length()) {
                    j++;
                }

                string tmp = "";
                while (!isupper(str[j]) && !isRuUpper(str[j]) && j < str.length()) {
                    tmp += str[j];
                    j++;
                }

                if (j != str.length() && !tmp.empty()) {
                    substring sub {i, tmp};
                    substrings->push_back(sub);
                }
            } else {
                j++;
            }
        }
    }

    if (substrings->size() == 0) {
        throw runtime_error("Подстроки не найдены");
    }
}

void outputString(const vector<string>* strings) {
    for (const string& str : *strings) {
        cout << str << endl;
    }
}

void outputStruct(const vector<substring>* strings) {
    for (const substring& str : *strings) {
        cout << str.str << endl;
    }
}

void findWithoutLatin(const vector<substring>* subs, substring* target) {
    for (const substring& substr : *subs) {
        bool flag = false;
        for (const char ch : substr.str) {
            if (isLatin(ch)) {
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            *target = substr;
            break;
        }
    }

    if (target->parent == -1) {
        throw runtime_error("Подстрока без латинских символов не найдена");
    }
}

void removeSpaces(string* str) {
    int i = 0;
    int prev_len = str->length();
    while (i < str->length()) {
        if ((*str)[i] == ' ') {
            i++;
            while ((*str)[i] == ' ' && i < str->length()) {
                str->erase(str->begin()+i);
            }
        } else {
            i++;
        }
    }

    if (prev_len == str->length()) {
        throw runtime_error("Лишние пробелы в исходной строке отсутствуют");
    }
}

int main() {
    setlocale(LC_ALL, "Russian_Russia.1251");
    cout << "Лабораторная работа №9\n";

    vector<string> strings;
    do {
        try {
            inputVector(&strings);
        } catch (const exception& err) {
            cout << err.what() << endl;
        }
    } while (strings.size() == 0);

    cout << "Введенные строки:\n";
    outputString(&strings);

    vector<substring> substrings;
    try {
        findSubstrings(&strings, &substrings);
    } catch (const exception& err) {
        cout << err.what() << endl;
        return 0;
    }

    cout << "Найденные подстроки:\n"; 
    outputStruct(&substrings);

    substring target {-1}; 

    try {
        findWithoutLatin(&substrings, &target);
    } catch (const exception& err) {
        cout << err.what() << endl;
        return 0;
    }

    try {
        removeSpaces(&strings[target.parent]);
    } catch (const exception& err) {
        cout << err.what() << endl;
        return 0;
    }

    cout << "Измененная строка: " << strings[target.parent] << endl;

    return 0;
}