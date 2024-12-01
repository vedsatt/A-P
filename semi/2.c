#include <stdio.h>

double sumDiagonal(double X[][100], int N) {
    double sum = 0.0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            sum += X[i][j];
        }
    }
    return sum;
}

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortSecDiagonal(double X[][100], int N) {
    double secDiagonal[100];
    for (int i = 0; i < N; i++) {
        secDiagonal[i] = X[i][N - 1 - i];
    }
    bubbleSort(secDiagonal, N);
    for (int i = 0; i < N; i++) {
        X[i][N - 1 - i] = secDiagonal[i];
    }
}

int main() {
    int N;
    double X[100][100];
    printf("¬ведите размер матрицы X (N): ");
    scanf("%d", &N);
    printf("¬ведите элементы матрицы X:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%lf", &X[i][j]);
        }
    }
    double sumBelowDiagonal = sumDiagonal(X, N);
    if (sumBelowDiagonal < 0) {
        sortSecDiagonal(X, N);
    }
    printf("–езультат:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2lf ", X[i][j]);
        }
        printf("\n");
    }
    return 0;
}
