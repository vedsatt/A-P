#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node {
    int data; 
    struct Node* next;
} Node;

void push(Node ** head, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = *head;
    *head = node;
}

Node* readFile(char *filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
    printf("Ошибка открытия входного файла\n");
    exit(1);
    }

    Node* head = NULL;
    int num;
    while(fscanf(file, "%d", &num) == 1) {
        push(&head, num);
    }
    fclose(file);

    return head;
}

int main() {
    setlocale(LC_ALL, "Russian");

    printf("Лабораторная работа №7\n");
    printf("Задание 1\n");
 
    char inputFileName[256], outputFileName[256];
    printf("Введите имя входного файла: ");
    scanf("%s", inputFileName);
    printf("Введите имя выходного файла: ");
    scanf("%s", outputFileName);

    Node* head = readFile(inputFileName);

    // Node* c = head;
    // while (c != NULL) {
    //     printf("%d\n", c->data);
    //     c = c->next;
    // }
}