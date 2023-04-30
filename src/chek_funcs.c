/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chek_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 03:50:50 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 05:00:26 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_same(t_stack *a)
{
	t_stack	*temp;
	int		second;

	while (a->next)
	{
		temp = a;
		second = 0;
		while (temp)
		{
			if (a->num == temp->num)
				if (++second > 1)
					error_msg(1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

int	is_sorted(t_stack *list)
{
	while (list->next)
	{
		if (list->num >= list->next->num)
			return (0);
		list = list->next;
	}
	return (1);
}

void	free_stack(t_stack **list)
{
	t_stack	*temp;

	if (!list || !(*list))
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}

/* void	check_result(t_stack *a, t_stack *b)
{
	while (a || b)
	{
		if (a)
		{
			printf("%d", a->num);
			a = a->next;
		}
		else
			printf("   ");
		if (b)
		{
			printf("     %d", b->num);
			b = b->next;
		}
		printf("\n");
	}
	if (is_sorted(a))
		write(1, "OK", 2);
	else
		write(1, "KO", 2);
}
 */