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
    printf("������������ ������ �2.\n");
    printf("������� 1.\n");
    printf("������� ���������� ����� ������� (n), ���������� �������� ������� (m), ���������� ��������� ������� (k):\n");
    while(scanf("%d %d %d", &n, &m, &k)!=3 || k<=0 || n<=0 ||m<=0){
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
    // ���� ������������� ������� Z[1:n, 1:m] � ������������� ������ F[1:k].
    // ������������ ������ Q, ��������� �� ��������� �������� ������� Z,
    // ������������� ����� ������� �������������� �������� ������� ������� ���� ������� � ������������� � ������� F.
    int q[n * m];
    int flag = 0;
    for (int i = 0; i < m; i++ ) {
        for (int j = 0; j < n; j++ ) {
            
        }
    }
}
