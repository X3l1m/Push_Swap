/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: seyildir <seyildir@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 04:10:34 by seyildir      #+#    #+#                 */
/*   Updated: 2023/04/30 09:18:41 by seyildir      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define  PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}	t_stack;

//Functions

t_stack	*next_max(t_stack *list, int last_max);
t_stack	*newnode(int num, t_stack *link);
t_stack	*before_last(t_stack *list);
t_stack	*get_max(t_stack *list);
t_stack	*get_min(t_stack *list);
t_stack	*last(t_stack *list);
void	push_other(t_stack **this, t_stack **other);
void	one_argv_fill(char *str, t_stack **a);
void	input_fill(char **argv, t_stack **a);
//void	check_result(t_stack *a, t_stack *b);
void	push_swap(t_stack **a, t_stack **b);
void	add_last(t_stack **list, int num);
void	fill_index(t_stack *a, int size);
void	swap_top_two(t_stack **list);
void	free_stack(t_stack **list);
void	go_top(t_stack **list);
void	go_bot(t_stack **list);
void	error_msg(int i);
int		get_pos(t_stack *list, int num);
int		stack_size(t_stack *list);
int		is_sorted(t_stack *list);
int		check_same(t_stack *a);

//Algorithms

void	radix_sort(t_stack **a, t_stack **b, int size);
void	sort_all(t_stack **a, t_stack **b, int size);
void	sort_five(t_stack **a, t_stack **b, int size);
void	sort_b(t_stack **a, t_stack **b, int size);
void	sort_three(t_stack **list);

//Actions

//Swap top two number in Stack A.
void	sa(t_stack **a);
//Swap top two number in Stack B.
void	sb(t_stack **b);
//Run sa and sb at the same time.
void	ss(t_stack **a, t_stack **b);
//Top number goes to bottom of Stack A.
void	ra(t_stack **a);
//Top number goes to bottom of Stack B.
void	rb(t_stack **b);
//Run ra and rb at the same time.
void	rr(t_stack **a, t_stack **b);
//Bottom number goes to top of Stack A.
void	rra(t_stack **a);
//Bottom number goes to top of Stack B.
void	rrb(t_stack **b);
//Run rra and rrb at the same time.
void	rrr(t_stack **a, t_stack **b);
//Push top of B to top of A.
void	pa(t_stack **a, t_stack **b);
//Push top of A to top of B.
void	pb(t_stack **a, t_stack **b);

#endif