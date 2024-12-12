#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

int main() {   
    setLocale(LC_ALL, "Russian");

    bool flag = false;
    char file[81];
    char newFile[81];
    
    do{
        printf("введите имя входного файла в формате name.txt: ");
        gets(file);

        printf("введите имя выходного файла в формате name.txt: ");
        gets(newFile);

        if (strcmp(file, newFile) == 0){
            printf("входной и выходной файл должны различаться\n");
        }
    }while (strcmp(file, newFile) == 0);

    flag = writetext(file, newFile);

    if (flag ==0){
        printf("файл пуст");
    }
    else{
        printf("данные в новом файле:\n");
        getArray(newFile);
    }
    
    return 0;
}