#include "push_swap.h"



stack	create_list(stack *a, char **argv)
{
	int		i;
	stack	head;

	i = 1;
	while (argv[i])
	{
		a = malloc(sizeof(stack));
		a->num = ft_atoi(argv[i++]);
		a->next = head;
		head = a;
	}
	return (a);
}