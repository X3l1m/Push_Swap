/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:24:52 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 09:22:46 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 9)
		sort_five(a, b, size);
	else if (size <= 150)
		sort_all(a, b, size);
	else if (size > 150)
		radix_sort(a, b, size);
}

void	error_msg(int i)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(i);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		one_argv_fill(argv[1], &a);
		if (!a->next)
			return (0);
	}
	else if (argc >= 3)
		input_fill(argv, &a);
	else
		return (0);
	check_same(a);
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
