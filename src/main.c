/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:24:52 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 05:34:20 by seyildir      ########   odam.nl         */
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
	long	num;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!ft_istrdigit(argv[i]))
			error_msg(1);
		num = ft_atoi(argv[i++]);
		if (num > INT_MAX || num < INT_MIN)
			error_msg(1);
		add_last(&a, (int)num);
	}
	check_same(a);
	if (!is_sorted(a))
		push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
}
