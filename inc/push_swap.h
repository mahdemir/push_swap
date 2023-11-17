/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 10:26:25 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:58:58 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX 21474836470
# define MIN -21474836480

/********** LIBRARIES *********************************************************/

# include <stdbool.h>
# include <stdio.h>
# include "../libft/inc/libft.h"

/********** STRUCTS ***********************************************************/

typedef struct s_stack
{
	int				num;
	int				index;
	int				push_cost;
	bool			above_middle;
	bool			cheapest;

	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}					t_stack;

/********** PROTOTYPES ********************************************************/

void	err_msg(char *msg);

void	check_args(int argc, char **argv);

int		stack_len(t_stack *stack);
bool	check_sort(t_stack *stack);
t_stack	*find_last(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort_algorithm(t_stack **a, t_stack **b);
t_stack	*find_cheapest(t_stack *stack);

void	free_stack(t_stack **stack);
void	free_matrix(char **matrix);

void	init_stack(t_stack **stack, int argc, char **argv);

void	set_index(t_stack *stack);

void	init_list_a(t_stack *a, t_stack *b);
void	init_list_b(t_stack *a, t_stack *b);

void	double_check(t_stack **a);
void	prep_stack(t_stack **stack, t_stack *cheapest, char name);

/* OPERATIONS */

// SWAP
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// PUSH
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// ROTATE
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// REVERSE ROTATE
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
