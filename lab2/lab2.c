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
    int k, m, n;
    printf("Лабораторная работа №2.\n");
    printf("Задание 1.\n");
    printf("Введите количество строк матрицы (n), количество столбцов матрицы (m), количество элементов массива (k):\n");
    while(scanf("%d %d %d", &n, &m, &k)!=3 || k<=0 || n<=0 ||m<=0){
        int c;
        while((c=getchar())!='\n' && c!=EOF){}
        printf("Произошла ошибка. Введите заново.\n");
    }
    int z[n][m];
    int f[k];
    printf("Введите элементы матрицы из %d строк и %d столбцов:", n, m);
    printf("\n");
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            while(scanf("%d", &z[i][j])!=1){
                int c;
                while((c=getchar())!='\n' && c!=EOF){}
        printf("Произошла ошибка. Введите заново.\n");
            }
        }
    }
    printf("Введите элементы массива из %d элементов:", k);
    printf("\n");
    for( int i=0; i<k; i++){
        while(scanf("%d", &f[i])!=1){
            int c;
            while((c=getchar())!='\n' && c!=EOF){}
  printf("Произошла ошибка. Введите заново.\n");
        }
    }
    printf("Матрица из %d строк и %d столбцов:\n", n, m);
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }
    printf("Массив из %d элементов:\n", k);
    for (int i=0; i<k; i++){
        printf("%d\n", f[i]);
    }
    // Даны целочисленная матрица Z[1:n, 1:m] и целочисленный массив F[1:k].
    // Сформировать массив Q, состоящий из элементов столбцов матрицы Z,
    // расположенных после первого отрицательного элемента каждого столбца этой матрицы и отсутствующих в массиве F.
    int q[n * m];
    int flag = 0;
    for (int i = 0; i < m; i++ ) {
        for (int j = 0; j < n; j++ ) {
            
        }
    }
}
