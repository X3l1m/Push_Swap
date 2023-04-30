#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

#include "libft/libft.h"
# include <limits.h>

typedef struct	s_list
{
int				num;
int				index;
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
stack	*get_max(stack *list);
stack	*get_min(stack *list);
int		is_sorted(stack *list);
void	sort_three(stack **list);
void	push_swap(stack **a, stack **b);
void	fill_index(stack *a, int size);
stack	*next_min(stack *list, int last_max);
int		check_same(stack *a);
void	error_msg(int i);
void	radix_sort(stack **a, stack **b, int size);
int		get_max_bits(stack *list);



//try
int		stack_size(stack *list);
int		get_pos(stack *list, int num);
void	sort_all(stack **a, stack **b, int size);
void 	sort_five(stack **a, stack **b, int size);
void	sort_b(stack **a, stack **b, int size);

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