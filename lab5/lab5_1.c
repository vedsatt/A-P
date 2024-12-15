#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void write(char *fileName, bool *flag) {
    FILE *file;
    float num;

    printf("������� �������������� ����� ����� ����� Enter (����� �����������, ���� �� ����� ������� ������):\n");
    file = fopen(fileName,"w");
    while (scanf("%f", &num)) {
        fprintf(file, "%f\n", num);
        *flag = true;
    }
    fclose(file);

    printf("������ �������� � ����� %s\n",fileName);
}

void countNums(char *fileName, int *cnt, bool *flag) {
    FILE *file;
    float num;

    if (!(file=fopen(fileName,"r+")))
    { 
        puts("���� �� ������");
        exit(1);
    }

    while (fscanf(file, "%f", &num) == 1) { 
        if (num > 0) {
            *flag = true;
            (*cnt)++;
        }
    }
    
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "Russian");

    printf("������������ ������ �5\n");
    printf("������� 1\n");

    int cnt = 0;
    bool flag;
    char name[81];

    char *point;
    do {
        flag = true;
        printf("������� ��� ����� � ������� name.txt: ");
        gets(name);

        point = strchr(name, '.');
        if (point == NULL) {
                flag = false;
                printf("��� ����� ������ ���� � ������� name.txt\n");
        } else {
            if (strcmp(point, ".txt") != 0 && !(strcmp(point, name) == 0)) {
                printf("��� ����� ������ ���� � ������� name.txt\n");
                flag = false;
            }
        }
    } while (!flag);

    flag = false;
    write(name, &flag);

    if (flag) {
        flag = false;
        countNums(name, &cnt, &flag);
        if (flag) {
            printf("���������� ������������� ����� = %d", cnt);
        } else {
            printf("� ����� ����������� ������������� �����");
        }
    }
    else {
        printf("� ����� ����������� �����");
    }
    return 0;
}
