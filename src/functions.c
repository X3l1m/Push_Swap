/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   functions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:51:17 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:17:10 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_min(t_stack *list)
{
	t_stack	*min;

	min = list;
	while (list->next)
	{
		if (list->next->num < min->num)
			min = list->next;
		list = list->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *list)
{
	t_stack	*max;

	max = list;
	while (list->next)
	{
		if (list->next->num > max->num)
			max = list->next;
		list = list->next;
	}
	return (max);
}

int	get_pos(t_stack *list, int num)
{
	int	pos;

	pos = 0;
	while (list)
	{
		if (list->num == num)
			return (pos);
		pos++;
		list = list->next;
	}
	return (-1);
}

int	stack_size(t_stack *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
