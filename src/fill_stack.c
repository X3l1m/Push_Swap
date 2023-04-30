/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 04:02:45 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*newnode(int num, t_stack *link)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error_msg(1);
	new->num = num;
	new->next = link;
	return (new);
}

void	add_last(t_stack **list, int num)
{
	t_stack	*new;
	t_stack	*temp;

	if (!*list)
		*list = newnode(num, NULL);
	else
	{
		temp = *list;
		new = newnode(num, NULL);
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_stack	*next_max(t_stack *list, int last_max)
{
	t_stack	*new_max;

	new_max = NULL;
	while (list)
	{
		if (list->num < last_max && (!new_max || list->num > new_max->num))
			new_max = list;
		list = list->next;
	}
	return (new_max);
}

void	fill_index(t_stack *a, int size)
{
	t_stack	*temp;

	temp = get_max(a);
	while (size)
	{
		temp->index = size--;
		temp = next_max(a, temp->num);
	}
}
