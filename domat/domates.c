#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

// Push işlemi
void push(t_stack **stack, int value)
{
    t_stack *new_elem;

    new_elem = (t_stack*)malloc(sizeof(t_stack));
    new_elem->value = value;
    new_elem->next = *stack;
    *stack = new_elem;
}

// Pop işlemi
int pop(t_stack **stack)
{
    int value;
    t_stack *temp;

    if (!*stack)
        return (-1);
    value = (*stack)->value;
    temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return (value);
}

int main()
{
    t_stack *stack;
    int arr[] = {1, 3, 5, 2};
    int i;

    stack = NULL;
    // Dizideki elemanları yığına ekleyin
    for (i = 0; i < sizeof(arr)/sizeof(int); i++)
        push(&stack, arr[i]);

    // Yığındaki elemanları ekrana yazdırın
    while (stack)
        printf("%d ", pop(&stack));

    return (0);
=======
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
>>>>>>> 3f492b13687e3f8d91f766efc2e898558c29e29e
}
