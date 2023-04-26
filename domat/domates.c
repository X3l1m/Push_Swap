#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int pop(Node** head) {
    int data = (*head)->data;
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return data;
}

void swap(Node** head) {
    int first = pop(head);
    int second = pop(head);
    push(head, first);
    push(head, second);
}

void rotate(Node** head) {
    int data = pop(head);
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = (Node*)malloc(sizeof(Node));
    temp->next->data = data;
    temp->next->next = NULL;
}

void reverseRotate(Node** head) {
    Node* temp = *head;
    *head = (*head)->next;
    temp->next = NULL;
    Node* ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void pushToOtherStack(Node** stackA, Node** stackB) {
    int data = pop(stackA);
    push(stackB, data);
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* stackA = NULL;
    Node* stackB = NULL;

    // 5 sayıyı yığın A'ya yerleştirin
    push(&stackA, 2);
    push(&stackA, 5);
    push(&stackA, 4);
    push(&stackA, 1);
    push(&stackA, 3);

    // Yığın A'yı sıralayın
    int count = 0;
    for (int i = 0; i < 5; i++) {
        for (Node* temp = stackA; temp->next != NULL; temp = temp->next) {
            if (temp->data > temp->next->data) {
                swap(&stackA);
                printf("sa ");
            }
        }
        pushToOtherStack(&stackA, &stackB);
        printf("pb ");
        count++;
    }

    // Yığın B'deki sayıları sıralayarak yığın A'ya geri aktarın
    for (int i = 0; i < count; i++) {
        for (Node* temp = stackB; temp->next != NULL; temp = temp->next) {
            if (temp->data < temp->next->data) {
                reverseRotate(&stackB);
                printf("rrb ");
            }
        }
        pushToOtherStack(&stackB, &stackA);
        printf("pa ");
   
    }

    // Son sıralama adımı
    for (Node* temp = stackA; temp->next != NULL; temp = temp->next) {
        if (temp->data > temp->next->data) {
            swap(&stackA);
            printf("sa ");
        }
    }

    // Sıralanmış yığın A'yı yazdırın
    printf("Sorted List: ");
    printList(stackA);

    return 0;
}
