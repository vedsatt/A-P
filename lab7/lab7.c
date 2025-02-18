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
    printf("������ �������� �������� �����\n");
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

    printf("������������ ������ �7\n");
    printf("������� 1\n");
 
    char inputFileName[256], outputFileName[256];
    printf("������� ��� �������� �����: ");
    scanf("%s", inputFileName);
    printf("������� ��� ��������� �����: ");
    scanf("%s", outputFileName);

    Node* head = readFile(inputFileName);

    // Node* c = head;
    // while (c != NULL) {
    //     printf("%d\n", c->data);
    //     c = c->next;
    // }
}