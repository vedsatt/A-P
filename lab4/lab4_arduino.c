#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define lmax 50
#define result_max 50

LiquidCrystal_I2C lcd(0x27, 16, 2); // ����� I2C � ������ ������

int extract(char *line, char **result, int *result_len, char *max, int *max_cnt, bool *flag, int *str_index, int index) {
    int local_result_len = 0;

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

            result[local_result_len] = (char *)malloc(lmax);
            strcpy(result[local_result_len], tmp);    
            local_result_len++;
        }
        i++;
    }
    *result_len = local_result_len;
    return local_result_len;
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

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();

    Serial.println("������������ ������ �4");

     Serial.println("������� ���������� �����:");
    while (!Serial.available());
    int k = Serial.parseInt();
    Serial.println(k);
    Serial.read();

    char lines[k][lmax];
    char max[lmax];

    for (int i = 0; i < k; i++) {
        Serial.print("������� ������ ");
        Serial.print(i + 1);
        Serial.println(": ");

        while (!Serial.available());
        String input = Serial.readStringUntil('\n');
        input.trim(); // ������� ������� ����� ������ � �������
        input.toCharArray(lines[i], lmax);

        // ������� ����� �� �������� �������� ����� ������
        while (Serial.available()) {
            Serial.read();
        }
    }


    bool flag = false;
    int max_cnt = 0;
    int str_index = 0;

    for (int i  = 0; i < k; i++) {
        int result_len = 0;
        char **result = (char **)malloc(result_max * sizeof(char *));
        result_len = extract(lines[i], result, &result_len, max, &max_cnt, &flag, &str_index, i);
        if (flag) {
            Serial.print("��������� ��������� � ������ ");
            Serial.print(i + 1);
            Serial.println(":");

            // ����� ���� ��������
            for (int j = 0; j < result_len; j++) {
                Serial.println(result[j]);
                free(result[j]);
            }

            free(result);
        } else {
            Serial.print("��������� � ������ ");
            Serial.print(i + 1);
            Serial.println(" �� �������.");
        }
        result_len = 0;
        flag = false;
    }

    // ����� ������ � ���� ���-��� ����
    if (max_cnt == 0) {
        Serial.println("� ������� ����������� ��������� ��� �����");
    } else {
        Serial.print("������ � ������������ ������ ����: ");
        Serial.println(max);
        insert_zero(lines[str_index]);
        Serial.print("��������� ������ � ������� ");
        Serial.print(str_index + 1);
        Serial.print(": ");
        Serial.println(lines[str_index]);

        // ����� �� ����� LCD1602
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Max: ");
        lcd.print(max);

        lcd.setCursor(0, 1);
        lcd.print(lines[str_index]);
    }
}

void loop() {
}
