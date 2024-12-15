#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; // Пин CS для MicroSD карты

void permutation(char *fileName, char *newFileName, bool *flag) {
    File file = SD.open(fileName, FILE_READ);
    File result = SD.open(newFileName, FILE_WRITE);

    char str[81];
    while (file.available()) {
        String line = file.readStringUntil('\n');
        line.trim(); // Убираем лишние пробелы
        line.toCharArray(str, 81);

        *flag = true;

        char newStr[81];
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            newStr[i] = str[len - i - 1];
        }
        newStr[len] = '\0';

        result.println(newStr);
    }

    file.close();
    result.close();
}

void output(char *fileName) {
    File result;
    char str[81];

    result = SD.open(fileName, FILE_READ);

    while (result.available()) {
        String line = result.readStringUntil('\n');
        line.trim(); // Убираем лишние пробелы
        Serial.println(line);
    }

    result.close();
}

void setup() {
    Serial.begin(9600);

    if (!SD.begin(chipSelect)) {
        Serial.println("Ошибка инициализации SD карты");
        return;
    }
    Serial.println("SD карта успешно инициализирована");

    Serial.println("Лабораторная работа №5");
    Serial.println("Задание 2");

    bool flag = false;
    char fileName[81];
    char newFile[81];

    while (true) {
        Serial.println("Введите имя входного файла в формате name.txt:");
        while (!Serial.available());
        String input = Serial.readStringUntil('\n');
        input.trim(); // Убираем лишние пробелы
        input.toCharArray(fileName, 81);

        Serial.println("Введите имя выходного файла в формате name.txt:");
        while (!Serial.available());
        input = Serial.readStringUntil('\n');
        input.trim(); // Убираем лишние пробелы
        input.toCharArray(newFile, 81);

        if (strcmp(fileName, newFile) == 0) {
            Serial.println("Входной и выходной файлы должны различаться");
        } else {
            break;
        }
    }

    permutation(fileName, newFile, &flag);

    if (!flag) {
        Serial.println("Файл пуст");
    } else {
        Serial.println("Данные, сохраненные в новый файл:");
        output(newFile);
    }
}

void loop() {}