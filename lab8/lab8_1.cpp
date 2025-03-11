#define lmax 200

#include <locale.h>
#include <iostream>

using namespace std;

void arrayInput(int* arr, int *arr_len, char name) {\
    cout << "Введите длину массива " << name << ": ";
    do {
        cin >> *arr_len;

        if (*arr_len == 0 && name == 'A') {
            cout << "Введите допустимую длину массива A (0 < len_a <= 200): ";
        }
    } while (*arr_len == 0 && name == 'A');
    
    cout << "Введите элементы массива " << name << endl;
    for (int i = 0; i < *arr_len; i++) {
        cin >> arr[i];
    }
}

int newArray(int* C, int len_c, int* A, int len_a, int* B, int len_b) {
    for (int i = 0; i < len_a; i++) {
        int curr = A[i];
        int flag = false;

        for (int j = 0; j < len_a && !flag; j++) {
            if (i != j && curr == A[j]) {
                flag = true;
            }
        }

        if (!flag) {
            int count = 0;
            for (int j = 0; j < len_b; j++) {
                if (curr == B[j]) {
                    count++;
                }
            }

            if (count != 1) {
                C[len_c] = curr;
                len_c++;
            }
        }
    }

    return len_c;
}

void outputArray(int* C, int len) {
    cout << "Массив C:\n";
    for (int i = 0; i < len; i++) {
        cout << C[i] << " ";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int A[lmax];
    int B[lmax];
    int len_a, len_b;

    int check = 0;

    cout << "Лабораторная работа №8\n";
    cout << "Задание 1\n";

    arrayInput(A, &len_a, 'A');
    arrayInput(B, &len_b, 'B');

    int C[lmax];
    int len_c = 0;

    len_c = newArray(C, len_c, A, len_a, B, len_b);

    if (len_c == 0) {
        cout << "Массив C пустой";
        return 1;
    }

    outputArray(C, len_c);

    return 0;
}