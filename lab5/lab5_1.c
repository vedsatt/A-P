#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

char writetext(char *fileName){
    FILE *file;
    char flag = 0;
    float q;

    printf("вводите действительные числа числа через Enter, числа вводятся до первого не числа: ");
    file=fopen(fileName,"w");
    while (scanf("%f", &q)){
        fprintf(file,"%f\n", q);
        flag = 1;
    }
    fclose(file);

    printf("Result is in file %s\n",fileName);

    return flag;
}

float getArray(char *fileName)
{
    FILE *file; 
    //char c;
    float min, q;
    if (!(file=fopen(fileName,"r")))
    { 
        puts("File not found");
        exit(1);
    }
    fscanf(file,"%f",&q);
    min = q;
    while(!feof(file)){
        if ((fscanf(file,"%f",&q))==1){
            if (fabs(q) < fabs(min)){
                min = q;
            }  
        }
    }
    
    fclose(file);
    return min;
}

int main(){
    setlocale(LC_ALL, "Russian");

    float w;
    bool flag;
    char name[81];

    printf("введите имя файла в формате name.txt: ");
    gets(name);
    flag = writetext(name);

    if (flag == 1){
        w = getArray(name);
        printf("результат = %f", w);
    }
    else{
        printf("в файле не записаны числа");
    }
    return 0;
}
