/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 09:02:27 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 09:15:40 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	str_to_stack(char *str, t_stack **a, int size)
{
	long	num;
	int		i;

	i = 0;
	while (i < size)
	{
		if (str[i])
		{
			if (!ft_istrdigit(str + i))
				error_msg(1);
			num = ft_atoi(str + i);
			if (num > INT_MAX || num < INT_MIN)
				error_msg(1);
			add_last(a, (int)num);
			while (str[i + 1])
				i++;
		}
		i++;
	}
}

void	one_argv_fill(char *str, t_stack **a)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' '
			&& str[i] != '-' && str[i] != '+')
			error_msg(1);
		else if (str[i] == ' ')
			str[i] = 0;
		i++;
	}
	str_to_stack(str, a, i);
}

void	input_fill(char **argv, t_stack **a)
{
	long	num;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!ft_istrdigit(argv[i]))
			error_msg(1);
		num = ft_atoi(argv[i++]);
		if (num > INT_MAX || num < INT_MIN)
			error_msg(1);
		add_last(a, (int)num);
	}
}
