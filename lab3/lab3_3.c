#include <stdio.h>
#include <locale.h>
#define lmax 200


void input_arr(int *len_a, int A[]) {
    int i, c;

    do{
        printf("Введите длину массива А:\n");
        c = scanf("%d", len_a);
        while(getchar() != '\n');
    } while (c<1);

    for (int i = 0; i < *len_a; i++) {
        int validInput = 0;
        do {
            printf("Введите элемент массива %d: ", i + 1);
            if (scanf("%d", &A[i]) == 1) {
                validInput = 1;
            } else {
                printf("Ошибка ввода.\n");
                while (getchar() != '\n');
            }
        } while (!validInput);
    }
    printf("\n");
}

void print_arr(int len_b, int B[], int len_c, int C[], int counts[]) {

    for (int i = 0; i < len_c; i++) {
        printf("Число %d встречается %d раз(а)\n", C[i], counts[i]);
    }
    printf("\n");

    printf("Массив В:\n");

    for(int i = 0; i<len_b; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
}

int count(int A[], int *C, int len_a, int *counts) {
    int len_c = 0;

    for (int i = 0; i <len_a; i++) {
        counts[i] = 0;
    }

    for(int i = 0; i < len_a; i++){
        int j = 0;
        while(j<len_c && (A[i] != C[j])) {
             j++;
        }

        if (j == len_c) {
            C[len_c] = A[i];
            len_c++;
        }
    }

    for (int i = 0; i<len_a; i++) {
        int flag = 0;

        for (int j = 0; j<len_c && !flag; j++) {
            if (C[j]==A[i]) {
                flag = 1;
                counts[j]++;
            }
        }
    }
    return len_c;
}

int repeats(int A[], int *B, int len_a) {
    int len_b = 0;
    for(int i = 0; i < len_a; i++){
        int j = 0;
        while(j<len_a && (A[i]!=A[j] || i == j)) {
            j++;
        }
        if (j < len_a){
            j = 0;
            while(j<len_b && (A[i] != B[j])) {
                j++;
            }
            if (j == len_b) {
                B[len_b] = A[i];
                len_b++;
            }
        }
    }
    return len_b;
}

int main() {
    setlocale (LC_ALL, "Russian");

    int A[lmax], B[lmax], C[lmax], counts[lmax], len_a, len_b, len_c;
    printf("Лабораторная работа № 3\n");
    printf("Задание №3\n");
    input_arr(&len_a, A);

    len_b = repeats(A, B, len_a);
    if (len_b==0){
        printf("Нет массива\n");
    } else{
        len_c = count(A, C, len_a, counts);
        print_arr(len_b, B, len_c, C, counts);
    }
    return 0;
}
