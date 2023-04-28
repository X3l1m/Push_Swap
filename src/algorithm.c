#include "../push_swap.h"

int	is_sorted(stack *list)
{
	while (list->next)
	{
		if (list->num >= list->next->num)
			return (0);
		list = list->next;
	}
	return (1);
}

stack	*get_max(stack *list)
{
	stack	*max;

	max = list;
	while (list->next)
	{
		if (list->next->num > max->num)
			max = list->next;
		list = list->next;
	}
	return (max);
}

stack	*get_min(stack *list)
{
	stack	*min;

	min = list;
	while (list->next)
	{
		if (list->next->num < min->num)
			min = list->next;
		list = list->next;
	}
	return (min);
}

void	sort_three(stack **list)
{
	int	highest;

	highest = get_max(*list)->num;
	if ((*list)->num == highest)
		ra(list);
	else if ((*list)->next->num == highest)
		rra(list);
	if ((*list)->num > (*list)->next->num)
		sa(list);
}


int stack_size(stack *list)
{
	int size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

int get_pos(stack *list, int num)
{
	int pos;

	pos = 0;
	while (list)
	{
		if (list->num == num)
			return (pos);
		pos++;
		list = list->next;
	}
	return -1;
}

void	sort_all(stack **a, stack **b, int size)
{
	int	chunk_count;

	chunk_count = size / 5;
	
}

void	sort_five(stack **a, stack **b, int size)
{
	int min;
	int i;

	while (size > 3)
	{
		min = get_min(*a)->num;
		i = get_pos(*a, min);
		if (i <= size-- / 2)
			while ((*a)->num != min)
				ra(a);
		else
			while ((*a)->num != min)
				rra(a);
		pb(a, b);

	}
	sort_three(a);
	while (stack_size(*b) > 0)
		pa(a, b);
}

void	sort_all(stack **a, stack **b, int size)
{
	
}