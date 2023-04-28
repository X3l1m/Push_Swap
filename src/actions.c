#include "../push_swap.h"

//Swap top two number in Stack A.
void	sa(stack **a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

//Swap top two number in Stack B.
void	sb(stack **b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

//Run sa and sb at the same time.
void	ss(stack **a, stack **b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}

//Top number goes to bottom of Stack A.
void	ra(stack **a)
{
	go_bot(a);
	write(1, "ra\n", 3);
}

//Top number goes to bottom of Stack B.
void	rb(stack **b)
{
	go_bot(b);
	write(1, "rb\n", 3);
}

//Run ra and rb at the same time.
void	rr(stack **a, stack **b)
{
	go_bot(a);
	go_bot(b);
	write(1, "rr\n", 3);
}

//Bottom number goes to top of Stack A.
void	rra(stack **a)
{
	go_top(a);
	write(1, "rra\n", 4);
}

//Bottom number goes to top of Stack B.
void	rrb(stack **b)
{
	go_top(b);
	write(1, "rrb\n", 4);
}

//Run rra and rrb at the same time.
void	rrr(stack **a, stack **b)
{
	go_top(a);
	go_top(b);
	write(1, "rrr\n", 4);
}

//Push top of B to top of A.
void	pa(stack **a, stack **b)
{
	push_other(b, a);
	write(1, "pa\n", 3);
}

//Push top of A to top of B.
void	pb(stack **a, stack **b)
{
	push_other(a, b);
	write(1, "pb\n", 3);
}
