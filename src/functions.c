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

void	add_first(stack **list, int num)
{
	if (!*list)
		*list = newnode(num, NULL);
	else
		*list = newnode(num, *list);
}

void	swap_top_two(stack **list)
{
	stack	*swp;

	swp = (*list)->next;
	(*list)->next = swp->next;
	swp->next = *list;
	*list = swp;
}

void	go_top(stack **list)
{
	stack	*last_node;
	stack	*new_last;

	last_node = last(*list);
	new_last = before_last(*list);
	last_node->next = *list;
	new_last->next = NULL;
	*list = last_node;
}

void	go_bot(stack **list)
{
	stack	*last_node;
	stack	*second_node;

	second_node = (*list)->next;
	last_node = last(*list);
	last_node->next = *list;
	(*list)->next = NULL;
	*list = second_node;
}

stack	*before_last(stack *list)
{
	while (list->next && list->next->next)
		list = list->next;
	return (list);
}

stack	*last(stack *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	push_other(stack **this, stack **other)
{
	stack	*new_first;

	new_first = (*this)->next;
	add_first(&*other, (*this)->num);
	free(*this);
	*this = new_first;
}