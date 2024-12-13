#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

void write(char *fileName){
    FILE *file = fopen(fileName, "w");
    char str[81];
    bool flag = true;

    printf("Введите строки файла:\n");
    while (flag) {
        fgets(str, 81, stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strlen(str) == 0) {
            flag = false;
        } else {
            fprintf(file, "%s\n", str);
        }
    }

    fclose(file);

    printf("Результат записан в файле %s\n", fileName);
}

void permutation(char *fileName, char *newFileName, bool *flag) {
    FILE *file = fopen(fileName,"r");
    FILE *result = fopen(newFileName, "w");
    
    char str[81];
    while (fscanf(file, "%80[^\n]%*c", str) == 1) {
        *flag = true;

        char newStr[81];
        for (int i = 0; i < strlen(str); i++) {
            newStr[i] = str[strlen(str) - i - 1];
        }
        newStr[strlen(str)] = '\0';

        fputs(newStr, result);
        fputs("\n", result);
    }

    fclose(file);
    fclose(result);
}

void output(char *fileName) {
    FILE *result; 
    char str[81];

    result=fopen(fileName, "r");

    while(fgets(str, 81, result)!=NULL){
        str[strcspn(str, "\n")] = '\0';
        puts(str);
    }
    
    fclose(result);
}

int main() {   
    setlocale(LC_ALL, "Russian");

    printf("Лабораторная работа №5\n");
    printf("Задание 2\n");

    bool flag = false;
    char fileName[81];
    char newFile[81];
    
    do {
        printf("Введите имя входного файла в формате name.txt: ");
        gets(fileName);

        printf("Введите имя выходного файла в формате name.txt: ");
        gets(newFile);

        if (strcmp(fileName, newFile) == 0) {
            printf("Входной и выходной файл должны различаться\n");
        }
    } while (strcmp(fileName, newFile) == 0);

    write(fileName);

    permutation(fileName, newFile, &flag);

    if (!flag) {
        printf("Файл пуст");
    }
    else {
        printf("Данные, сохраненные в новый файл:\n");
        output(newFile);
    }
    
    return 0;
}