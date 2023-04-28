#include "../push_swap.h"

stack	*newnode(int num, stack *link)
{
	stack	*new = malloc(sizeof(stack));
	new->num = num;
	new->next = link;
	return new;
}

void	add_last(stack **list, int num)
{
	if (!*list)
		*list = newnode(num, NULL);
	else
	{
		stack *new; 
		stack *temp;
 
		temp = *list;
		new = newnode(num, NULL);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

stack	*next_min(stack *list, int last_max)
{
	stack	*new_max;

	new_max = NULL;
	while (list)
	{
		if (list->num < last_max && (!new_max || list->num > new_max->num))
			new_max = list;
		list = list->next;
	}
	return (new_max);
}

void	fill_index(stack *a, int size)
{
	stack	*temp;

	temp = get_max(a);
	while (size)
	{
		temp->index = size--;
		temp = next_min(a, temp->num);
	}
	
}