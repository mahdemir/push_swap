/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 06:31:28 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 11:16:51 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
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

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*find_max(t_stack *stack)
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

t_stack	*find_min(t_stack *stack)
{
	int		i;
	t_stack	*min;

	if (!stack)
		return (NULL);
	i = stack->num;
	min = stack;
	while (stack)
	{
		if (stack->num < i)
		{
			i = stack->num;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == true)
		{
			return (stack);
		}
		stack = stack->next;
	}
	return (NULL);
}
