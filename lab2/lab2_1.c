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
    int k, m, n;
    int lmax = 200;
    printf("������������ ������ �2.\n");
    printf("������� 1.\n");
    printf("������� ���������� ����� ������� (n), ���������� �������� ������� (m), ���������� ��������� ������� (k):\n");
    while(scanf("%d %d %d", &n, &m, &k)!=3 || k<=0 || n<=0 || n > lmax || m > lmax || m<=0){
        int c;
        while((c=getchar())!='\n' && c!=EOF){}
        printf("��������� ������. ������� ������.\n");
    }
    int z[n][m];
    int f[k];
    printf("������� �������� ������� �� %d ����� � %d ��������:", n, m);
    printf("\n");
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            while(scanf("%d", &z[i][j])!=1){
                int c;
                while((c=getchar())!='\n' && c!=EOF){}
        printf("��������� ������. ������� ������.\n");
            }
        }
    }
    printf("������� �������� ������� �� %d ���������:", k);
    printf("\n");
    for( int i=0; i<k; i++){
        while(scanf("%d", &f[i])!=1){
            int c;
            while((c=getchar())!='\n' && c!=EOF){}
  printf("��������� ������. ������� ������.\n");
        }
    }
    printf("������� �� %d ����� � %d ��������:\n", n, m);
    for(int i=0; i<n; i++){
        for( int j=0; j<m; j++){
            printf("%d ", z[i][j]);
        }
        printf("\n");
    }
    printf("������ �� %d ���������:\n", k);
    for (int i=0; i<k; i++){
        printf("%d\n", f[i]);
    }

    int cnt = 0;
    int q[200] = {0};
    int flag = 0;
    for (int i = 0; i < m; i++ ) {
        int tmp = -1;
        for (int j = 0; j < n; j++ ) {
            int flag2 = 0;
            int num = z[j][i];
            if (num < 0 && flag == 0) {
                flag = 1;
                tmp = j;
            }
            printf("%d, %d\n", tmp, j);
            if (flag == 1 && j != tmp) {
                for (int x = 0; x < k; x++) {
                    if (f[x] == num) {
                        flag2 = 1;
                    }
                }
                if (flag2 == 0) {
                    q[cnt] = num;
                    cnt++;
                    }
            }
        }
        flag = 0;
    }
    printf("������ Q:\n");
    for (int i=0; i<cnt; i++) {
        printf("%d\n", q[i]);
    }
    printf("������� 2\n");


    return 0;
}
