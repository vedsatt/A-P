#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#define lmax 1000

int extract(char *line, char result[][lmax], char *max, int *max_cnt, bool *flag, int *str_index, int index) {
    int result_len = 0;

    // ���������� �������� � ���������� �� � ������ � ������������
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
            // ������� ���-�� ���� � ������
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

void insert_zero(char *string, int *check) {
    int i = 0;
    while (i < strlen(string)) {
        if (string[i] == '1') {
            *check = 1;
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

    printf("������������ ������ �4\n");
    printf("������� ���������� �����: ");

    int k;
    scanf("%d", &k);
    getchar();

    char lines[k][lmax];
    char result[1000][lmax];
    char max[lmax];

    for (int i = 0; i < k; i++) {
        printf("������� ������ %d: ", i + 1);
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
            printf("��������� ��������� � ������ %d:\n", i+1);

            // ����� ���� ��������
            for (int j = 0; j < result_len; j++) {
                printf("%s\n", result[j]);
            }

            // ��������� ������� � ������������
            for (int j = 0; j < result_len; j++) {
                strcpy(result[j], "");
            }
        } else {
            printf("��������� � ������ %d �� �������.\n", i+1);
        }
        result_len = 0;
        flag = false;
    }

    // ����� ������ � ���� ���-��� ����
    if (max_cnt == 0) {
        printf("� ������� ����������� ��������� ��� �����");
    } else {
        printf("������ � ������������ ������ ����: %s\n", max);
        int check = 0;
        insert_zero(lines[str_index], &check);
        if (check) {
            printf("��������� ������ � ������� %d: %s\n", str_index+1, lines[str_index]);
        } else {
            printf("������ �� �������� ������");
        }
    }
}