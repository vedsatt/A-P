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
    int lmax = 200;
    printf("Лабораторная работа №2.\n");
    printf("Задание 1.\n");
    printf("Введите количество строк матрицы (n), количество столбцов матрицы (m), количество элементов массива (k):\n");
    while(scanf("%d %d %d", &n, &m, &k)!=3 || k<=0 || n<=0 || n > lmax || m > lmax || m<=0){
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

    int cnt = 0;
    int q[200] = {0};
    int flag = 0;
    for (int i = 0; i < m; i++ ) {
        int tmp = -1;
        for (int j = 0; j < n; j++ ) {
            int flag2 = 0;
            int num = z[j][i];
            if (num < 0 && flag == 0) {
                flag = 1;
                tmp = j;
            }
            printf("%d, %d\n", tmp, j);
            if (flag == 1 && j != tmp) {
                for (int x = 0; x < k; x++) {
                    if (f[x] == num) {
                        flag2 = 1;
                    }
                }
                if (flag2 == 0) {
                    q[cnt] = num;
                    cnt++;
                    }
            }
        }
        flag = 0;
    }
    printf("Массив Q:\n");
    for (int i=0; i<cnt; i++) {
        printf("%d\n", q[i]);
    }
    printf("Задание 2\n");


    return 0;
}
