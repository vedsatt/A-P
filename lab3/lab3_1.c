#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void input(int x[], int y[]) {
    printf("Введите x1, x2, x3:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &x[i]);
    }

    printf("Введите y1, y2, y3:\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &y[i]);
    }
    
}

float area(int x[], int y[]) {
    float res = abs((x[0]-x[2])*(y[1]-y[2])-(x[1]-x[2])*(y[0]-y[2]))/2;

    return res; 
}

void output(float res) {
    printf("\n");
    printf("Результат: %f", res);
}

int main() {
    setlocale(LC_ALL, "Russian");

    printf("Лабораторная работа № 3\n");
    printf("Задание №1\n");
    int x[3], y[3]; 
    input(x, y);
    output(area(x, y));
    
    return 0;
}
