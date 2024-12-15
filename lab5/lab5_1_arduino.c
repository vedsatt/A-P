#include <SD.h>

const int chipSelect = 10;

void writeToFile(char *fileName, bool *flag) {
    File file = SD.open(fileName, FILE_WRITE);
    char line[10];
    bool check = true;

    Serial.println("Введите действительные числа через Enter (числа считываются, пока не будет введено end):");
    if (!file) { 
        Serial.println("Ошибка открытия файла для записи");
        return;
    }

    while (check) {
        Serial.read();
        while (Serial.available() == 0);
        Serial.readBytesUntil('\n', line, 9);
        float num = atof(line);
        if (strcmp(line, "end") == 0) {
          check = false;
        }
        if (num != 0.0 || strcmp(line, "0") == 0) { 
          file.println(num);
          *flag = true;
       }
      }
        file.close();

        Serial.print("Результат записан в файле ");
        Serial.println(fileName);
    }

void countNums(char *fileName, int *cnt, bool *flag) {
    File file;
    float num;

    file = SD.open(fileName, FILE_READ);
    if (!file) {
        Serial.println("Файл не найден!");
        return;
    }

    while (file.available()) {
        String line = file.readStringUntil('\n');
        num = line.toFloat();
        if (num > 0) {
            *flag = true;
            (*cnt)++;
        }
    }
    file.close();
}

void setup() {
    Serial.begin(9600);

    // Инициализация SD карты
    if (!SD.begin(chipSelect)) {
        Serial.println("Ошибка инициализации SD карты");
        return;
    }
    Serial.println("SD карта успешно инициализирована.");

    Serial.println("Лабораторная работа №5");
    Serial.println("Задание 1");

    int cnt = 0;
    bool flag;
    char name[81];

    Serial.println("введите имя файла в формате name.txt: ");
    Serial.read();
    while (Serial.available() == 0);
    Serial.readBytesUntil('\n', name, 80);

    flag = false;
    writeToFile(name, &flag);

    if (flag) {
        flag = false;
        countNums(name, &cnt, &flag);
        if (flag) {
            Serial.print("Количество положительных чисел = ");
            Serial.println(cnt);
        } else {
            Serial.println("В файле отсутствуют положительные числа");
        }
    } else {
        Serial.println("В файле отсутствуют числа");
    }
}

void loop() {}
