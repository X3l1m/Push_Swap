/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_top.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:37:05 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*before_last(t_stack *list)
{
	while (list->next && list->next->next)
		list = list->next;
	return (list);
}

void	go_top(t_stack **list)
{
	t_stack	*last_node;
	t_stack	*new_last;

	last_node = last(*list);
	new_last = before_last(*list);
	last_node->next = *list;
	new_last->next = NULL;
	*list = last_node;
}

void	rra(t_stack **a)
{
	go_top(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	go_top(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	go_top(a);
	go_top(b);
	write(1, "rrr\n", 4);
}
