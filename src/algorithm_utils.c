/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 11:43:57 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:47:52 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sort(t_stack *stack)
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

void	prep_stack(t_stack **stack, t_stack *cheapest, char name)
{
	if (!*stack || !cheapest || !name)
		return ;
	while (*stack != cheapest)
	{
		if (cheapest->above_middle == true && name == 'a')
			ra(stack);
		else if (cheapest->above_middle == false && name == 'a')
			rra(stack);
		else if (cheapest->above_middle == true && name == 'b')
			rb(stack);
		else if (cheapest->above_middle == false && name == 'b')
			rrb(stack);
	}
}

void	double_check(t_stack **a)
{
	t_stack	*min;

	if (!*a)
		return ;
	min = find_min(*a);
	while ((*a)->num != min->num)
	{
		if (min->above_middle)
			ra(a);
		else
			rra(a);
	}
}

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	if (!stack)
		return ;
	i = 0;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}
