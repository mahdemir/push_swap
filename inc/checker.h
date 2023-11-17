/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 12:32:53 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 15:16:45 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

void	err_msg_bonus(char *msg);

void	check_args_bonus(int argc, char **argv);

bool	check_sort_bonus(t_stack *stack);

t_stack	*find_last_bonus(t_stack *stack);

void	init_stack_bonus(t_stack **stack, int argc, char **argv);

/* OPERATIONS */

// SWAP
void	sa_bonus(t_stack **a);
void	sb_bonus(t_stack **b);
void	ss_bonus(t_stack **a, t_stack **b);

// PUSH
void	pa_bonus(t_stack **a, t_stack **b);
void	pb_bonus(t_stack **b, t_stack **a);

// ROTATE
void	ra_bonus(t_stack **a);
void	rb_bonus(t_stack **b);
void	rr_bonus(t_stack **a, t_stack **b);

// REVERSE ROTATE
void	rra_bonus(t_stack **a);
void	rrb_bonus(t_stack **b);
void	rrr_bonus(t_stack **a, t_stack **b);

#endif
