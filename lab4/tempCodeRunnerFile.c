// 8 4 8

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define lmax 1000

int extract(char *line, char result[][lmax], char *max, int *max_cnt, bool *flag, int *str_index, int index) {
    int result_len = 0;

    // нахождение подстрок и добавление их в массив с результатами
    int i = 0;
    while (i < strlen(line)) {
        if (line[i] != '.') {
            *flag = true;
            char tmp[lmax] = "";
            while (line[i] != '.' && line[i] != '\0') {
                char ch[2];
                ch[0] = line[i];
                ch[1] = '\0';
                strcat(tmp, ch);
                i++;
            }

            int tmp_cnt = 0;
            // находим кол-во цифр в строке
            for (int i = 0; i < strlen(tmp); i++) {
                if (tmp[i] >= '0' && tmp[i] <= '9')
                    tmp_cnt++;
            }
            if (tmp_cnt > *max_cnt) {
                strcpy(max, tmp);
                *max_cnt = tmp_cnt;
                *str_index = index;
            }
            tmp_cnt = 0;

            strcpy(result[result_len], tmp);    
            result_len++;
        }
        i++;
    }
    return result_len;

}

void insert_zero(char *string) {
    int i = 0;
    while (i < strlen(string)) {
        if (string[i] == '1') {
            char tmp[strlen(string)+2];
            strncpy(tmp, string, i+1);
            tmp[i+1] = '0';
            tmp[i+2] = '\0';
            strcat(tmp, string+i+1);
            strcpy(string, tmp);
            i++;
        } 
        i++;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    printf("Лабораторная работа №4\n");
    printf("Введите количество строк: ");

    int k;
    scanf("%d", &k);
    getchar();

    char lines[k][lmax];
    char result[1000][lmax];
    char max[lmax];

    for (int i = 0; i < k; i++) {
        printf("Введите строку %d: ", i + 1);
        fgets(lines[i], lmax, stdin);
        lines[i][strcspn(lines[i], "\n")] = '\0';
    }

    bool flag = false;
    int max_cnt = 0;
    int str_index = 0;

    for (int i  = 0; i < k; i++) {
        int result_len = 0;
        result_len = extract(lines[i], result, max, &max_cnt, &flag, &str_index, i);
        if (flag) {
            printf("Найденные подстроки в строке %d:\n", i+1);

            // вывод всех подстрок
            for (int j = 0; j < result_len; j++) {
                printf("%s\n", result[j]);
            }

            // обнуление массива с результатами
            for (int j = 0; j < result_len; j++) {
                strcpy(result[j], "");
            }
        } else {
            printf("Подстроки в строке %d не найдены.\n", i+1);
        }
        result_len = 0;
        flag = false;
    }

    // вывод строки с макс кол-вом цифр
    if (max_cnt == 0) {
        printf("В строках отсутствуют цифры");
    } else {
        printf("Строка с максимальным числом цифр: %s\n", max);
        insert_zero(lines[str_index]);
        printf("Изменённая строка с номером %d: %s\n", str_index+1, lines[str_index]);
    }
}