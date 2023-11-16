/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 14:54:31 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/16 16:07:58 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revRotate(t_stack **stack)
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

void	rra(t_stack **a, bool print)
{
	revRotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool print)
{
	revRotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	revRotate(a);
	revRotate(b);
	if (print)
		write(1, "rrr\n", 4);
}
