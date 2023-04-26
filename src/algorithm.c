#include "../push_swap.h"

int	find_highest(stack *list)
{
	int	highest;

	highest = list->num;
	while (list->next)
	{
		if (list->next->num > highest)
			highest = list->next->num;
		list = list->next;
	}
	return (highest);
}






void	little_short(stack **list)
{
	int	highest;

	highest = find_highest(*list);
	if ((*list)->num == highest)
		ra(list);
	else if ((*list)->next->num == highest)
		rra(list);
	if ((*list)->num > (*list)->next->num)
		sa(list);
}