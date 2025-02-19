#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef struct Node {
    int data; 
    struct Node* next;
} Node;

void push(Node** head, int val) {
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

Node* deleteMax(Node** head) {
    Node* dummyNode = (Node*)malloc(sizeof(Node));
    dummyNode->next = *head;
    Node* max = *head;
    Node* prevMax = dummyNode;

    Node* curr = dummyNode;
    while (curr->next != NULL) {
        if (curr->next->data > max->data) {
            max = curr->next;
            prevMax = curr;
        }
        curr = curr->next;
    }
    free(dummyNode);

    prevMax->next = max->next;
    free(max);

    *head = dummyNode->next;
    free(dummyNode);
}

void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = *head;
        Node* prev = NULL;

        while (current->next != NULL && current->next->data != 0) {
            if (current->data > current->next->data) {
                Node* temp = current->next;
                current->next = temp->next;
                temp->next = current;

                if (prev == NULL) {
                    *head = temp;
                } else {
                    prev->next = temp;
                }

                prev = temp;
                swapped = true;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } while (swapped);
}

void writeToFile(char *filename, Node** head) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Ошибка открытия выходного файла\n");
        exit(1);
    }

    Node* curr = *head;
    while (curr != NULL) {
        fprintf(file, "%d\n", curr->data);
        curr = curr->next;
    }
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
    if (head == NULL) {
        printf("Задан пустой список");
        return 0;
    }

    deleteMax(&head);
    printf("Обновленный после второй части задания список:\n");
    Node* c = head;
    while (c != NULL) {
        printf("%d\n", c->data);
        c = c->next;
    }

    sortList(&head); 
    printf("Конечный список записан в файл %s\n", outputFileName);
    writeToFile(outputFileName, &head);  

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}