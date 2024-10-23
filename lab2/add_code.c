#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void cp() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main() {
    cp();
    int n, m;
    int lmax = 200;
    printf("Лабораторная работа №2.\n");
    printf("Дополнительный код (Вар №1)\n");
    printf("Введите количество строк матрицы (n), количество столбцов матрицы (m):\n");
    while(scanf("%d %d", &n, &m)!=2 || n<=0 || n > lmax || m > lmax || m<=0){
        int c;
        while((c=getchar())!='\n' && c!=EOF){}
        printf("Произошла ошибка. Введите заново.\n");
    }
    int arr[n][m];
    printf("Введите элементы матрицы из %d строк и %d столбцов:", n, m);
    printf("\n");
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            while(scanf("%d", &arr[i][j])!=1){
                int c;
                while((c=getchar())!='\n' && c!=EOF){}
        printf("Произошла ошибка. Введите заново.\n");
            }
        }
    }
    int min = arr[0][0];
    int max = arr[0][0];
    int index_max_i, index_max_j, index_min_i, index_min_j;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
           if (arr[i][j] > max) {
            max = arr[i][j];
            index_max_i = i;
            index_max_j = j;
           }
            if (arr[i][j] < min) {
            min = arr[i][j];
            index_min_i = i;
            index_min_j = j; 
            }      
        }
    }
    if (abs(min) > max) {
        int tmp = arr[index_max_i][index_max_j];
        arr[index_max_i][index_max_j] = arr[index_min_i][index_min_j];
        arr[index_min_i][index_min_j] = tmp;
    }
    printf("Преобразованная матрица из %d строк и %d столбцов:\n", n, m);
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}