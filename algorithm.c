#include "push_swap.h"


void	little_short(stack **a, stack **b)
{
	while (((*a)->next))
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
		pb(a, b);
	}
	while (((*b)->next))
	{
		if ((*b)->num > (*b)->next->num)
			sa(b);
		pa(a, b);
	}
}