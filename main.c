#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack	*a;
	//stack	*b;
	
	a = create_list(++argv);
	printf("%d", a->num);
}

