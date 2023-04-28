#include "../push_swap.h"

void	free_stack(stack **list)
{
	stack	*temp;

	if (!list || !(*list))
		return;
	while (*list)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
	*list = NULL;
}