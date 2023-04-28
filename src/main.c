#include "../push_swap.h"

void push_swap(stack **a, stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
	{
		fill_index(*a, size);
		sort_all(a, b, size);
	}
}

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		i;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!ft_istrdigit(argv[i]))
			return (write(1, "non digit\n", 10) > 0) ? 1 : 0;
		add_last(&a, ft_atoi(argv[i++]));
	}
	
/* 	if (!is_sorted(a))
		push_swap(&a, &b); */
 	sort_all(&a, &b, stack_size(a));
	//sort_all(&a, &b, stack_size(a));
/* 	while (a || b)
	{
		if (a){
			printf("%d", a->num);
			a = a->next;
		}
		else
			printf("   ");
		if (b){
			printf("     %d", b->num);
			b = b->next;
		}
		printf("\n");
	} */
	
	//free_stack(&a);
	//free_stack(&b);
	//system("leaks a.out");
}
