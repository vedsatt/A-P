#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void write(char *fileName, bool *flag) {
    FILE *file;
    float num;

    printf("Ââåäèòå äåéñòâèòåëüíûå ÷èñëà ÷èñëà ÷åðåç Enter (÷èñëà ñ÷èòûâàþòñÿ, ïîêà íå áóäåò ââåäåíà ñòðîêà):\n");
    file = fopen(fileName,"w");
    while (scanf("%f", &num)) {
        fprintf(file, "%f\n", num);
        *flag = true;
    }
    fclose(file);

    printf("Ðåçóëüòàò çàïèñàí â ôàéëå %s\n",fileName);
}

void countNums(char *fileName, int *cnt, bool *flag) {
    FILE *file;
    float num;

    if (!(file=fopen(fileName,"r+")))
    { 
        puts("Ôàéë íå íàéäåí");
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

    printf("Ëàáîðàòîðíàÿ ðàáîòà ¹5\n");
    printf("Çàäàíèå 1\n");

    int cnt = 0;
    bool flag;
    char name[81];

    char *point;
    do {
        flag = true;
        printf("Ââåäèòå èìÿ ôàéëà â ôîðìàòå name.txt: ");
        gets(name);

        point = strchr(name, '.');
        if (point == NULL) {
                flag = false;
                printf("èìÿ ôàéëà äîëæíî áûòü â ôîðìàòå name.txt\n");
        } else {
            if (strcmp(point, ".txt") != 0 && !(strcmp(point, name) == 0)) {
                printf("èìÿ ôàéëà äîëæíî áûòü â ôîðìàòå name.txt\n");
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
            printf("Êîëè÷åñòâî ïîëîæèòåëüíûõ ÷èñåë = %d", cnt);
        } else {
            printf("Â ôàéëå îòñóòñòâóþò ïîëîæèòåëüíûå ÷èñëà");
        }
    }
    else {
        printf("Â ôàéëå îòñóòñòâóþò ÷èñëà");
    }
    return 0;
}
