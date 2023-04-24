#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		i;

	if (argc < 3)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (!ft_istrdigit(argv[i]))
			return (write(1, "non digit\n", 10) > 0) ? 1 : 0;
		add_last(&a, ft_atoi(argv[i++]));
	}
	little_short(&a, &b);
	while (a || b)
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
	}
	
	//free_stack(&a);
	//free_stack(&b);
	//system("leaks a.out");
}