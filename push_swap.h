#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

#include "libft/libft.h"

typedef struct	s_list
{
int				num;
struct s_list	*next;
}				stack;

stack	*newnode(int num, stack *link);
void	add_last(stack **list, int num);
void	add_first(stack **list, int num);
void	swap_top_two(stack **list);
void	go_top(stack **list);
void	go_bot(stack **list);
stack	*before_last(stack *list);
stack	*last(stack *list);
void	push_other(stack **this, stack **other);
void	free_stack(stack **list);
int		find_highest(stack *list);
void	little_short(stack **list);

//try:


//Actions:
//Swap top two number in Stack A.
void	sa(stack **a);
//Swap top two number in Stack B.
void	sb(stack **b);
//Run sa and sb at the same time.
void	ss(stack **a, stack **b);
//Top number goes to bottom of Stack A.
void	ra(stack **a);
//Top number goes to bottom of Stack B.
void	rb(stack **b);
//Run ra and rb at the same time.
void	rr(stack **a, stack **b);
//Bottom number goes to top of Stack A.
void	rra(stack **a);
//Bottom number goes to top of Stack B.
void	rrb(stack **b);
//Run rra and rrb at the same time.
void	rrr(stack **a, stack **b);
//Push top of B to top of A.
void	pa(stack **a, stack **b);
//Push top of A to top of B.
void	pb(stack **a, stack **b);

#endif