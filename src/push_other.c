/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_other.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:43:12 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 04:13:55 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_other(t_stack **this, t_stack **other)
{
	t_stack	*new_first;

	new_first = *this;
	*this = (*this)->next;
	new_first->next = *other;
	*other = new_first;
}

void	pa(t_stack **a, t_stack **b)
{
	push_other(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_other(a, b);
	write(1, "pb\n", 3);
}
