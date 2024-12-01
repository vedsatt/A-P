#include <stdio.h>
#include <limits.h> 
#include <math.h>
#include <locale.h>
#define lmax 10 
 
void input(int a[][lmax], int *n) 
{ 
    int i, j; 
 
    printf("Введите размер квадратной матрицы n: ");   
    scanf("%d", n); 
    printf("Введите матрицу размером %d на %d \n",*n,*n); 
    for(i=0; i<*n; i++) 
        for(j=0; j<*n; j++) 
            scanf("%d", a[i]+j); 
} 

void output(int a[][lmax], int n)    
{ 
     int i, j; 
    printf("\nМатрица %d на %d:\n",n,n);

    for(i=0; i<n; i++) 
    { 
        for(j=0; j<n; j++) 
            printf("%d ", a[i][j]); 
     printf("\n"); 
     }     
} 
 
int z(int n, int  b[][lmax]) 
{ 
    int limit, min,max,i, j;
    min= INT_MAX;

    for (j=0;j<n;j++) { 
        max=b[0][j];   
        for (i=0; i<n; i++) {
            if (b[i][j]>=max) {
            max=b[i][j]; 
        }
    }

        if (max<min) {
           min=max; 
        }
    } 
    return min; 
} 
 
int main() { 
    setlocale (LC_ALL, "Russian");

    printf("Лабораторная работа № 3\n");
    printf("Задание №2\n");
    int b[lmax] [lmax],G, n; 
    input(b,&n);
    output(b,n);
    G=z(n,b); 
    printf("\nG = %d", G); 
    return 0; 
}
