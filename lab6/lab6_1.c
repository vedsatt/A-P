#include <stdio.h>
#include <locale.h>
#include <string.h>
#define lmax 200

struct Model {
    char serial[6];
    int number;
};

struct Date {
    int year;
    char month[20];
};

struct Car {
    char firm[lmax];
    struct Model model;
    float price;
    struct Date release_date;
    char color[20];
    float engine_capacity;
};

void input_cars(struct Car cars[], int *n) {
    int check;
    do {
        printf("Введите количество автомобилей: ");
        check = scanf("%d", n);
        while (getchar() != '\n');
    } while (check != 1 || *n <= 0 || *n > lmax);

    for (int i = 0; i < *n; i++) {
        printf("\nАвтомобиль №%d\n", i + 1);
        printf("Фирма: ");
        gets(cars[i].firm);
        printf("Модель (серийный номер): ");
        gets(cars[i].model.serial);
        printf("Модель (номер): ");
        scanf("%d", &cars[i].model.number);
        while (getchar() != '\n');
        do {
            printf("Цена: ");
            check = scanf("%f", &cars[i].price);
            while (getchar() != '\n');
        } while (check != 1 || cars[i].price <= 0);
        do {
            printf("Дата выпуска (год): ");
            check = scanf("%d", &cars[i].release_date.year);
            while (getchar() != '\n');
        } while (check != 1 || cars[i].release_date.year < 1900 || cars[i].release_date.year > 2024);
        printf("Дата выпуска (месяц): ");
        gets(cars[i].release_date.month);
        printf("Цвет: ");
        gets(cars[i].color);
        do {
            printf("Объем двигателя: ");
            check = scanf("%f", &cars[i].engine_capacity);
            while (getchar() != '\n'); 
        } while (check != 1 || cars[i].engine_capacity <= 0);
    }
}

void find_cars(struct Car cars[], int cnt) {
    int check;
    float cap = 0;
        do {
            printf("\nВведите объем двигателя для поиска: ");
            check = scanf("%f", &cap);
            while (getchar() != '\n'); 
        } while (check != 1 || cap <= 0);

    int find = 0;
    for (int i = 0; i < cnt; i++) {
        if (cars[i].engine_capacity == cap) {
            if (!find) {
                printf("\nПодходящие модели:\n");
            }
            printf("Автомобиль №%d:\n", i + 1);
            printf("  Фирма: %s\n", cars[i].firm);
            printf("  Модель: %s-%d\n", cars[i].model.serial, cars[i].model.number);
            printf("  Цена: %.2f\n", cars[i].price);
            printf("  Дата выпуска: %s %d\n", cars[i].release_date.month, cars[i].release_date.year);
            printf("  Цвет: %s\n", cars[i].color);
            printf("  Объем двигателя: %.1f\n", cars[i].engine_capacity);
            printf("\n");
            find = 1;
        }

        if (!find) {
            printf("Нет автомобилей с соответствующим объемом двигателя");
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct Car cars[lmax];
    int cars_cnt = 0;
    input_cars(cars, &cars_cnt);

    int res_cnt = 0;
    find_cars(cars, cars_cnt);

    return 0;
}