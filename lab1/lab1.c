#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void cp() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// ������� ������ � ���������� ���� �������� ���������
float* CreateArray(int n, float x, float h, float a) {
    float* array = (float*)malloc(n * sizeof(float));

    for (int i = 1; i <= n; i++) {
        array[i-1] = cos(i * h) - cos(a * x + i * h);
    }

    return array;
}

int Delete(float** array, int* size) {
    int index_max;
    int index_pos = -1;
    float max_elem = -1;
    int len = 0;

    // ������� ��������� �������. ������� � ������ ���� ������� �� ������
    for (int i = 0; i < *size; i++) {
        if ((*array)[i] > 0) {
            index_pos = i;
        }
        if (fabs((*array)[i]) > max_elem) {
            max_elem = fabs((*array)[i]);
            index_max = i;
        }
    }

    // ���� ��� �������������� �����
    if (index_pos == -1) {
        return -1;
    }
    // ������� ��� � ���� ������� ���������
    int start = index_max < index_pos ? index_max : index_pos;
    int end = index_max > index_pos ? index_max : index_pos;

    // ���� ������� ��������� ��� ��������� �����
    if ((end - start) < 2){
        return -2;
    }

    // ������� �������� � ����� ��������� ��������
    for (int i = start + 1; i < (*size - (end - start - 1)); i++) {
        (*array)[i] = (*array)[i + (end - start - 1)];
    }
    *size = *size - (end - start - 1);
    *array = (float*)realloc(*array, *size * sizeof(float));

    return 0;
}

float ArithmeticMean(float* array, int size) {
    float min_elem = 10;
    float max_elem = -10;
    int index_min, index_max;;
    float sum = 0.0;
    int cnt = 0;

    // ������� ������� �� ��� ����� � �� ���� �����
    for (int i = 0; i < size; i++) {
        if (fabs(array[i]) < min_elem) {
            min_elem = fabs(array[i]);
            index_min = i;
        }
        if (fabs(array[i]) > max_elem) {
            max_elem = fabs(array[i]);
            index_max = i;
        }
    }

    // ��������� ���������� ��� � ���� ���������
    int start = index_min < index_max ? index_min : index_max;
    int end = index_min > index_max ? index_min : index_max;

    // ������� ���-�� ��������� � �� �����
    for (int i = start + 1; i < end; i++) {
        sum += array[i];
        cnt++;
    }

    return (cnt > 0) ? (sum / cnt) : NAN;
}

int main() {
    cp();
    float x, h, a;
    int n, check;
    float arifm;
    int limit = 200;

        do {
        check = scanf("%d", &n);  // scanf ���������� 1, ���� ������� �����
        
        // ���� ���� �� ����� (check != 1)
        if (check != 1) {
            printf("Error: ������� �� �����! ����������, ������� ����� �����.\n");
            
            // ������� ������ �����, ����� �������� ������������
            while (getchar() != '\n');
            continue;  // ���������� ��������� �������� � ����������� ���� �����
        }
        
        // �������� ���������
        if (n > limit) {
            printf("Error: ����� ��������� ����� (%d)\n", limit);
        } else if (n <= 0) {
            printf("Error: ����� ������ ���� ������ 0\n");
        }
    } while (n > limit || n <= 0);

    scanf("%f %f %f", &a, &h, &x);
    float* array = CreateArray(n, x, h, a);
    for (int i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
    check = Delete(&array, &n);
    switch (check) {
        case -1:
            printf("Notice: ��� �������������� ��������\n");
            break;
        case -2:
            printf("Notice: ��������� ������������� � ������ ������������ �������� ��������� ����� ��� ���������\n");
            break;
        default:
            for (int i = 0; i < n; i++) {
                printf("%f ", array[i]);
            }
            printf("\n");
            break;
    }

    arifm = ArithmeticMean(array, n);
    if (isnan(arifm)) {
        printf("Notice: ��� �������� ��������\n");
    } else {
        printf("%g\n", arifm);
    }

    free(array);
    return 0;
} 
