#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void cp() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

int main() {
    cp();
    int k;

    printf("������������ ������ �2.\n");
    printf("������� 2.\n");

    printf("������� ����� �������: ");
    while(scanf("%d", &k)!=1){
        int c;
        while((c=getchar())!='\n' && c!=EOF){}
        printf("��������� ������. ������� ������.\n");
    }
    
    int arr[k];

    printf("������� �������� ������� �� %d ���������:", k);
    printf("\n");
    for( int i=0; i<k; i++){
        while(scanf("%d", &arr[i])!=1){
            int c;
            while((c=getchar())!='\n' && c!=EOF){}
  printf("��������� ������. ������� ������.\n");
        }
    }

    printf("������ �� %d ���������:\n", k);
    for (int i=0; i<k; i++){
        printf("%d\n", arr[i]);
    }

    for (int i = 0; i < k; i ++) {
        int num = arr[i];
        int flag = 0;
        if (num < 0) {
            flag = 1;
            num = abs(num);
        }
        if (num > 9) {
            int res = 0;
            for (int i = (int)log10(abs(num)); i > 0; i--) {
            int pow10i = 1;
            for (int j = 0; j < i; j++) {
                pow10i *= 10;
            }
            int pow10i_1 = 1;
            for (int j = 0; j < i - 1; j++) {
                pow10i_1 *= 10;
            }

            int tmp1 = num / pow10i % 10 * pow10i_1;
            int tmp2 = num / pow10i_1 % 10 * pow10i;
            int tmp_res = num % pow10i_1;
            res = res / (pow10i * 10) * (pow10i * 10);
            res = res + tmp2 + tmp1 + tmp_res;
            num = res;
                }
            if (flag == 1) {
                arr[i] = res * (-1);
            } else {
                arr[i] = res;
            }
        } else {
            break;
        }

        }

    printf("��������������� ������ �� %d ���������:\n", k);
    for (int i=0; i<k; i++){
        printf("%d\n", arr[i]);
    }
} 
