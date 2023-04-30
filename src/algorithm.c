/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:52:35 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **list)
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

void	sort_five(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	i;
	int	pushed;

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

void	sort_b(t_stack **a, t_stack **b, int size)
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

void	sort_all(t_stack **a, t_stack **b, int size)
{
	int	half;
	int	b_size;
	int	i;

	fill_index(*a, size);
	half = size / 2;
	i = 0;
	if (size % 2)
		i = 1;
	while (size > half)
	{
		if ((*a)->index > half + i)
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

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	size_b;
	int	max_bit;

	i = 0;
	max_bit = 0;
	fill_index(*a, size);
	while ((size >> max_bit) != 0)
		max_bit++;
	while (max_bit > i)
	{
		j = 0;
		while (j++ < size)
		{
			if ((*a)->index >> i & 1)
				ra(a);
			else
				pb(a, b);
		}
		size_b = stack_size(*b);
		while (size_b--)
			pa(a, b);
		i++;
	}
}
