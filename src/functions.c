#include "../push_swap.h"

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

int	check_same(stack *a)
{
	stack	*temp;
	int		second;

	while (a->next)
	{
		temp = a;
		second = 0;
		while (temp)
		{
			if (a->num == temp->num)
				if (++second > 1)
					error_msg(1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}