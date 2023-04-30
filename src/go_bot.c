/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   go_bot.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:33:51 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*last(t_stack *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	go_bot(t_stack **list)
{
	t_stack	*last_node;
	t_stack	*second_node;

	second_node = (*list)->next;
	last_node = last(*list);
	last_node->next = *list;
	(*list)->next = NULL;
	*list = second_node;
}

void	ra(t_stack **a)
{
	go_bot(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	go_bot(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	go_bot(a);
	go_bot(b);
	write(1, "rr\n", 3);
}
