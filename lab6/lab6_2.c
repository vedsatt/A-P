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

int read_cars(struct Car cars[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("������ �������� ����� ��� ������\n");
        return 0;
    }

    int cnt = 0;
    while (fscanf(file, "%s %s %d %f %d %s %s %f",
                  cars[cnt].firm,
                  cars[cnt].model.serial,
                  &cars[cnt].model.number,
                  &cars[cnt].price,
                  &cars[cnt].release_date.year,
                  cars[cnt].release_date.month,
                  cars[cnt].color,
                  &cars[cnt].engine_capacity) == 8) {
        cnt++;
    }

    fclose(file);
    return cnt;
}

void write_cars(struct Car cars[], int cnt, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("������ �������� ����� ��� ������\n");
        return;
    }

    for (int i = 0; i < cnt; i++) {
        fprintf(file, "       ���������� �%d\n", i + 1);
        fprintf(file, "  �����: %s\n", cars[i].firm);
        fprintf(file, "  ������: %s-%d\n", cars[i].model.serial, cars[i].model.number);
        fprintf(file, "  ����: %.2f\n", cars[i].price);
        fprintf(file, "  ���� �������:\n");
        fprintf(file, "    ���: %d\n", cars[i].release_date.year);
        fprintf(file, "    �����: %s\n", cars[i].release_date.month);
        fprintf(file, "  ����: %s\n", cars[i].color);
        fprintf(file, "  ����� ���������: %.1f\n", cars[i].engine_capacity);
        fprintf(file, "\n");
    }

    fclose(file);
    printf("���������� �������� � ����: %s\n", filename);
}

int find_cars(struct Car cars[], int cnt, float cap, struct Car result[]) {
    int res_cnt = 0;
    for (int i = 0; i < cnt; i++) {
        if (cars[i].engine_capacity == cap) {
            result[res_cnt++] = cars[i];
        }
    }
    return res_cnt;
}

int main() {
    setlocale(LC_ALL, "Russian");

    struct Car cars[lmax];
    struct Car result[lmax];
    int cars_cnt = 0;

    cars_cnt = read_cars(cars, "input.txt");
    if (cars_cnt == 0) {
        printf("�� ������� ��������� ������ �� ����� ��� ���� ����.\n");
        return 1;
    }

    float cap;
    printf("������� ����� ��������� ��� ������: ");
    scanf("%f", &cap);

    int res_cnt = find_cars(cars, cars_cnt, cap, result);

    if (res_cnt > 0) {
        write_cars(result, res_cnt, "output.txt");
    } else {
        printf("����������� � ������� ��������� %.1f �� �������.\n", cap);
    }

    return 0;
}