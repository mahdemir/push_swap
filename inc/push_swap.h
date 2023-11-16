/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 10:26:25 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/16 16:26:10 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/********** LIBRARIES *********************************************************/

# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/inc/libft.h"

/********** STRUCTS ***********************************************************/

typedef	struct s_stack
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

void	errMsg(char *msg);

void	checkArgs(char **argv);

int		stackLen(t_stack *stack);
bool	checkSort(t_stack *stack);
t_stack	*findLast(t_stack *stack);
t_stack *findMax(t_stack *stack);
void	sortThree(t_stack **stack);
void	sortAlgorithm(t_stack **a, t_stack **b);
t_stack	*findCheapest(t_stack *stack);

void	initStack(t_stack **stack, int argc, char **argv);

/* OPERATIONS */

// SWAP
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

// PUSH
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **b, t_stack **a, bool print);

// ROTATE
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

// REVERSE ROTATE
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

#endif
