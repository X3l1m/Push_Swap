#include "push_swap.h"


void	little_short(stack **a, stack **b)
{
	stack *temp;

	temp = *a;
	int i = 0;
	int count = 0;
	while (i < 5)
	{
		while (temp->next)
		{
			if(temp->num > temp->next->num)
				sa(a);
			temp = temp->next;
		}
		pb(a, b);
		i++;
		count++;
	}
	i = 0;
	temp = *b;
	while (i < count)
	{
		while (temp->next)
		{
			if(temp->num < temp->next->num)
				rrb(b);
			temp = temp->next;
		}
		pa(a, b);
		i++;
	}
	
	temp = *a;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			sa(a);
		temp = temp->next;
	}
	
}