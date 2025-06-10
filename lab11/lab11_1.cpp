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

// ����������� ������ ������� F(n)
int recursiveF(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return recursiveF(n - 1) + 2 * recursiveF(n - 2);
}

// ����������� ������ ������� F(n)
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

    cout << "������������ ������ �11" << endl;
    cout << "����� �1" << endl;
    int n;
    bool isValid = false;

    do {     
        cout << "������� �������� n: ";
        // ���������, �������� �� ���� ������
        if (!(cin >> n)) {
            cout << "������: ������� �� �����! ����������, ��������� ����.\n";
            
            // ������� ���� ������ � ����� �����
            cin.clear();
            continue;
        }

        // ���������, ��� ����� > 0
        if (n <= 0) {
            cout << "������: ����� ������ ���� ������ 0.\n";
        } else {
            isValid = true; // ���� ���������, ������� �� �����
        }
    } while (!isValid);
    
    auto startRecursive = high_resolution_clock::now();
    int resultRecursive = recursiveF(n);
    auto stopRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<milliseconds>(stopRecursive - startRecursive);
    
    cout << "����������� ���������: " << resultRecursive << endl;
    cout << "����� ���������� (��������): " << durationRecursive.count() << " (��)" << endl;
    
    auto startIterative = high_resolution_clock::now();
    int resultIterative = iterativeF(n);
    auto stopIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<milliseconds>(stopIterative - startIterative);
    
    cout << "����������� ���������: " << resultIterative << endl;
    cout << "����� ���������� (��������): " << durationIterative.count() << " (��)" << endl;
    
    return 0;
}