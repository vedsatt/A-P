#define lmax 200

#include <locale.h>
#include <iostream>
#include <stdexcept>

using namespace std;

struct coords {
    int x;
    int y;
};

void inputMatrix(int (*A)[lmax], int* len) {
    cout << "Введите размер матрицы: ";
    do {
        cin >> *len;
        if (*len <= 0 || *len > 200) {
            cout << "Введите допустимую длину (0 < len < 201): ";
        }
    } while (*len <= 0 || *len > 200);

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < *len; i++) {
        for (int j = 0; j < *len; j++) {
            cin >> *(*(A + i) + j);
        }
    }
}

void relocate(int (*A)[lmax], int len) {
    int min = INT32_MAX;
    coords min_crd = {-1, -1};
    int neg = 1;
    coords neg_crd = {-1, -1};
    bool flag = false;

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            int curr = *(*(A + i) + j);

            if (curr > 0 && curr < min) {
                min = curr;
                min_crd.x = i;
                min_crd.y = j;
            }

            if (!flag && curr < 0) {
                neg = curr;
                neg_crd.x = i;
                neg_crd.y = j;
                flag = true;
            }
        }
    }

    if (neg == 1) {
        throw invalid_argument("Отрицательный элемент отсутствует");
    }

    if (min == INT32_MAX) {
        throw invalid_argument("Положительный элемент отсутствует");
    }

    int tmp = *(*(A + neg_crd.x) + neg_crd.y);
    *(*(A + neg_crd.x) + neg_crd.y) = *(*(A + min_crd.x) + min_crd.y);
    *(*(A + min_crd.x) + min_crd.y) = tmp;
}

void outputMatrix(int (*A)[lmax], int len) {
    cout << "Измененная матрица:\n";
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
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
        relocate(A, len);
    } catch (const exception& err) {
        cerr << err.what() << endl;
        return 1;
    }

    outputMatrix(A, len);

    return 0;
}