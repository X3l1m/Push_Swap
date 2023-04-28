#include "push_swap.h"


void	little_short(stack **a, stack **b)
{
	stack *mem = *a;
	while ((*a)->next)
	{
		if((*a)->num > (*a)->next->num)
			sa(a);
		*a = (*a)->next;
	}
	*a = mem;
}