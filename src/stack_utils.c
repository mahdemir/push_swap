/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 06:31:28 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/13 11:38:48 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stackLen(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

bool	checkSort(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*findLast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*findMax(t_stack *stack)
{
	int		i;
	t_stack	*max;

	if (!stack)
		return (NULL);
	i = stack->num;
	max = stack;
	while (stack)
	{
		if (stack->num > i)
		{
			i = stack->num;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}
