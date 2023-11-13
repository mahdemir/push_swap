/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 21:25:34 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/13 15:03:52 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setIndex(t_stack *stack)
{
	int	i;
	int	middle;
	
	if (!stack)
		return ;
	i = 0;
	middle = stackLen(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		i++;
		stack = stack->next;
	}
}

void	setTarget_a(t_stack *a, t_stack *stack_b)
{
	t_stack	*b;
	t_stack	*target;
	long	best_match;

	
	while (a)
	{
		best_match = LONG_MIN;
		b = stack_b;
		while (b)
		{
			if (b->num < a->num && b->num > best_match)
			{
				best_match = b->num;
				target = b;
			}
			b = b->next;
		}
		
		if (best_match == LONG_MIN)
		{
			a->target = findMax(b);
		}
		else
		{
			a->target = target;
		}
		a = a->next;
	}
}

void	initList_a(t_stack *a, t_stack *b)
{
	setIndex(a);
	setIndex(b);
	setTarget_a(a, b);
}

void	sortAlgorithm(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stackLen(*a);
	if (len_a-- > 3 && !checkSort(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !checkSort(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !checkSort(*a))
	{
		initList_a(*a, *b);
	}
	
}
