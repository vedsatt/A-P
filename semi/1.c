#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#define lmax 200

int f(int A[][lmax], int B[lmax], int n, int m, int k) {
    bool flag;
    int count = 0;

    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < k; j++) {
            if (i == B[j])
                flag = true;
        }
        if (flag == false) {
            for (int q = 0; q < m; q++) {
            count += A[i][q];
            }
        }
        if (flag == true) {
            for (int q = 0; q < m; q++) {
                A[i][q] = 0;
            }
        }
    }
    return count;
}

int main() {
    setlocale (LC_ALL, "Russian");

    printf("����������� ������ �1\n�������� ���� �������� ���248\n������� �7\n");

    int A[lmax][lmax], B[lmax], n, m, k; 
 
    printf("������� ��������� ������� n �� m: ");   
    scanf("%d%d", &n, &m);
    printf("������� ������� �������� %d �� %d \n", n, m); 
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) 
            scanf("%d", &A[i][j]);

    printf("������� ����� ������� B: ");   
    scanf("%d", &k);
    printf("������� �������� ������� B\n"); 
    for(int i=0; i<k; i++)
        scanf("%d", &B[i]);
    printf("\n");

    int count = 0;
    count = f(A, B, n, m, k);

    // ����� �������
    // for (int i = 0; i < k; i++)
    //     printf("%d ", B[i]);

    // ����� �������
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("%d", count);
}