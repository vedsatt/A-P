#include <iostream>
#include <chrono>
#include <windows.h>
#include <algorithm>
#include <limits>

using namespace std;
using namespace std::chrono;

void CP() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Рекурсивная версия функции F(n)
int recursiveF(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return recursiveF(n - 1) + 2 * recursiveF(n - 2);
}

// Итеративная версия функции F(n)
int iterativeF(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    int prevPrev = 0; // F(1)
    int prev = 1;     // F(2)
    int current;
    
    for (int i = 3; i <= n; ++i) {
        current = prev + 2 * prevPrev;
        prevPrev = prev;
        prev = current;
    }
    
    return current;
}

int main() {
    CP();

    cout << "Лабораторная работа №11" << endl;
    cout << "Часть №1" << endl;
    int n;
    bool isValid = false;

    do {     
        cout << "Введите значение n: ";
        // Проверяем, является ли ввод числом
        if (!(cin >> n)) {
            cout << "Ошибка: Введено не число! Пожалуйста, повторите ввод.\n";
            
            // Очищаем флаг ошибки и буфер ввода
            cin.clear();
            continue;
        }

        // Проверяем, что число > 0
        if (n <= 0) {
            cout << "Ошибка: Число должно быть больше 0.\n";
        } else {
            isValid = true; // Ввод корректен, выходим из цикла
        }
    } while (!isValid);
    
    auto startRecursive = high_resolution_clock::now();
    int resultRecursive = recursiveF(n);
    auto stopRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<milliseconds>(stopRecursive - startRecursive);
    
    cout << "Рекурсивный результат: " << resultRecursive << endl;
    cout << "Время выполнения (рекурсия): " << durationRecursive.count() << " (мс)" << endl;
    
    auto startIterative = high_resolution_clock::now();
    int resultIterative = iterativeF(n);
    auto stopIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<milliseconds>(stopIterative - startIterative);
    
    cout << "Итеративный результат: " << resultIterative << endl;
    cout << "Время выполнения (итерация): " << durationIterative.count() << " (мс)" << endl;
    
    return 0;
}