#include <stdio.h>
#include <locale.h>
#include <limits.h>
#define lmax 200


void input(int a[][lmax], int *n, int *m) { 
    int i, j; 
 
    printf("������� ������ ������� n �� m: ");   
    scanf("%d %d", n, m);
    printf("������� ������� �������� %d �� %d \n",*n,*m); 
    for(i=0; i<*n; i++) 
        for(j=0; j<*m; j++) 
            scanf("%d", a[i]+j);
} 

void find(int a[lmax][lmax], int n, int m, int *index, int *nums) {
    nums[0] = INT_MAX, nums[1] = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > nums[1]) {
                nums[1] = a[i][j];
                index[1] = i;
            }
            if (a[i][j] < nums[0]) {
                nums[0] = a[i][j];
                index[0] = i;
            }
        }
    }
    printf("min: %d\n", nums[0]);
    printf("max: %d\n", nums[1]);
}

void replace(int a[lmax][lmax], int n, int m, int index[lmax]) {
    int tmp[lmax]; 
    for (int i = 0; i < m; i++) {
        tmp[i] = a[index[0]][i]; //����� ������ � min � tmp
    }
        for (int i = 0; i < m; i++) {
        a[index[0]][i] = a[index[1]][i]; //��������� ������ � max � ������ � min
    }
        for (int i = 0; i < m; i++) {
        a[index[1]][i] = tmp[i]; // ��������� ������ � min �� tmp ������� � max
    }

    int i, j; 
    printf("\n���������� �������:\n");
    for(i=0; i<n; i++) { 
        for(j=0; j<m; j++) 
            printf("%d ", a[i][j]); 
    printf("\n"); 
    }    
}

int main() {
    int index[lmax], nums[lmax], a[lmax][lmax], n, m;
    setlocale (LC_ALL, "Russian");

    input(a, &n, &m);

    int i, j; 
    printf("\n������� %d �� %d:\n",n, m);
    for(i=0; i<n; i++) { 
        for(j=0; j<m; j++) 
            printf("%d ", a[i][j]); 
    printf("\n");
    }
    printf("\n");    

    find(a, n, m, index, nums);
    replace(a, n, m, index);

    return 0;
}