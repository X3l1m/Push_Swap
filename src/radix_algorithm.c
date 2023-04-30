#include "../push_swap.h"

void	radix_sort(stack **a, stack **b, int size)
{
	int	i;
	int	j;
	int	size_b;
	int	max_bit;

	i = 0;
	max_bit = 0;
	fill_index(*a, size);
	while ((size >> max_bit) != 0)
		max_bit++;
	while (max_bit > i++)
	{
		j = 0;
		while (j++ < size)
		{
			if ((*a)->index >> i & 1)
				ra(a);
			else
				pb(a, b);
		}
		size_b = stack_size(*b);
		while (size_b--)
			pa(a, b);
	}
}
