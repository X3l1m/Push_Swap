/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_top_two.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:38:32 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_top_two(t_stack **list)
{
	t_stack	*swp;

	swp = (*list)->next;
	(*list)->next = swp->next;
	swp->next = *list;
	*list = swp;
}

void	sa(t_stack **a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}
