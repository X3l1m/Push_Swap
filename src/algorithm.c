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

void	sort_five(stack **a, stack **b, int size)
{
	int min;
	int i;
	int pushed;

	pushed = 0;
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
		pushed++;
	}
	sort_three(a);
	while (pushed--)
		pa(a, b);
}


void	sort_b(stack **a, stack **b, int size)
{
	int	max;
	int	i;

	while (size > 1)
	{
		max = get_max(*b)->num;
		i = get_pos(*b, max);
		if (i <= size-- / 2)
			while ((*b)->num != max)
				rb(b);
		else
			while ((*b)->num != max)
				rrb(b);
		pa(a, b);
	}
	pa(a, b);
}


void	sort_all(stack **a, stack **b, int size)
{
	int	half;
	int b_size;

	fill_index(*a, size);
	half = size / 2;
	while (size > half)
	{
		if ((*a)->index > half)
			ra(a);
		else
		{
			pb(a, b);
			size--;
		}
	}
	b_size = stack_size(*b);
	sort_five(a, b, size);
	sort_b(a, b, b_size);
}

