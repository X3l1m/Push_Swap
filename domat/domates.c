#include <stdio.h>
#include <stdlib.h>

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
}
