#include "../libft/libft.h"

/* typedef struct	domates
{
int 			patates;
struct domates	*next;
}				stack;

stack	*create(int h)
{ 
    stack	*i = NULL;
	stack	*head;
	if (i)
		head = i;
    i = (stack*)malloc(sizeof(stack));
	i->patates = h;
	i->next = head;
	return i;
}

void bul(stack *ag)
{
	printf("%d", ag->next->patates);
	ag = ag->next;
	printf("%d", ag->next->patates);
}

int main()
{
	stack *ag;
	stack *dom;
	int h = 5;
	while (h--)
	{
		ag = create(h);
	}
	//dom = ag;
	//bul(ag);
	printf("%d", ag->next->patates);


    return 0;
}
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int 			num;
	struct stack	*next;
} stack;

stack	*newnode(int num, stack *link)
{
	stack	*new = malloc(sizeof(stack));
	new->num = num;
	new->next = link;
	return new;
}

void	push_last(stack **list, int num)
{
	if (!*list)
		*list = newnode(num, NULL);
	else
	{
		stack *new = newnode(num, NULL);
        stack *temp = *list;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
	}
}

void	push_first(stack **list, int num)
{
	if (!*list)
		*list = newnode(num, NULL);
	else
		*list = newnode(num, *list);
}

int main() {
	stack	*a = NULL;
	for(int i = 0; i < 5; i++)
	push_last(&a, i);
	push_first(&a, 10);
	printf("%d\n", a->next->next->num);
	//system("leaks a.out");
}
