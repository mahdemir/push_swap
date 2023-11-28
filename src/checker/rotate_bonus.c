/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 13:49:27 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/27 14:13:51 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

static void	rotate_bonus(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = find_last_bonus(*stack);
	(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
}

void	ra_bonus(t_stack **a)
{
	rotate_bonus(a);
}

void	rb_bonus(t_stack **b)
{
	rotate_bonus(b);
}

void	rr_bonus(t_stack **a, t_stack **b)
{
	rotate_bonus(a);
	rotate_bonus(b);
}
