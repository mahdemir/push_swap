/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 14:54:31 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/27 14:13:48 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

static void	rev_rotate_bonus(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	rra_bonus(t_stack **a)
{
	rev_rotate_bonus(a);
}

void	rrb_bonus(t_stack **b)
{
	rev_rotate_bonus(b);
}

void	rrr_bonus(t_stack **a, t_stack **b)
{
	rev_rotate_bonus(a);
	rev_rotate_bonus(b);
}
