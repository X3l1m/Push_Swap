#include "../push_swap.h"

void push_swap(stack **a, stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b, size);
	else if (size > 5)
	{
		fill_index(*a, size);
		sort_all(a, b, size);
	}
}
void	error_msg(int i)
{
	write(1, "Error\n", 6);
	exit(i);
}
int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
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
	free_stack(&a);
	free_stack(&b);
	//system("leaks push_swap");
}
