// В заданной целочисленной прямоугольной матрице поменять местами минимальный положительный и первый отрицательный элементы 11 43
#define lmax 200

#include <locale.h>
#include <iostream>
#include <stdexcept>

using namespace std;

void inputMatrix(int (*A)[lmax], int* len) {
    cout << "Введите размер матрицы: ";
    do {
    cin >> *len;
    if (*len <= 0) {
        cout << "Введите допустимую длину (0 < len < 201):";
    }
    } while (*len <= 0);

    cout << "Введите элементы матрицы\n";
    for (int i = 0; i < *len; i++) {
        for (int j = 0; j < *len; j++) {
            cin >> A[i][j];
        }
    }
}

void relocate(int (*A)[lmax], int* len) {
    int min = INT32_MAX;
    int min_crd[2] = {-1, -1};
    int neg = 1;
    int neg_crd[2] = {-1, -1};
    bool flag = false;

    for (int i = 0; i < *len; i++) {
        for (int j = 0; j < *len; j++) {
            if (A[i][j] > 0 && A[i][j] < min) {
                min = A[i][j];
                min_crd[0] = i;
                min_crd[1] = j;
            }

            if (!flag && A[i][j] < 0) {
                neg = A[i][j];
                neg_crd[0] = i;
                neg_crd[1] = j;
                flag = true;
            }
        }
    }

    if (neg == 1) {
        throw invalid_argument("отрицательный элемент отсутствует");
    }

    if (min == INT32_MAX) {
        throw invalid_argument("положительный элемент отсутствует");
    }

    int tmp = A[neg_crd[0]][neg_crd[1]];
    A[neg_crd[0]][neg_crd[1]] = A[min_crd[0]][min_crd[1]];
    A[min_crd[0]][min_crd[1]] = tmp;
}

void outputMatrix(int (*A)[lmax], int* len) {
    cout << "Измененная матрица:\n";
    for (int i = 0; i < *len; i++) {
        for (int j = 0; j < *len; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Лабораторная работа №8\n" << "Задание 1\n"; 

    int A[lmax][lmax];
    int len = 0;

    inputMatrix(A, &len);

    try {
        relocate(A, &len);
    } catch (const exception& err) {
        cerr << "Ошибка: " << err.what() << endl;
    }

    outputMatrix(A, &len);

    return 0;
}