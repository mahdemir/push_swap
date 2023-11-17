/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_list_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 02:51:42 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:59:33 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_a(t_stack *a, t_stack *stack_b)
{
	t_stack	*b;
	t_stack	*target;
	long	best_match;

	while (a)
	{
		best_match = MIN;
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
		if (best_match == MIN)
			a->target = find_max(stack_b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	calculate_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (a->above_middle == false)
		{
			a->push_cost = len_a - a->index;
		}
		if (a->target->above_middle == true)
		{
			a->push_cost += a->target->index;
		}
		else
		{
			a->push_cost += len_b - a->target->index;
		}
		a = a->next;
	}
}

static void	set_cheapest(t_stack *stack)
{
	long	cheapest;
	t_stack	*tmp;

	if (!stack)
		return ;
	cheapest = MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest)
		{
			cheapest = stack->push_cost;
			tmp = stack;
		}
		stack = stack->next;
	}
	tmp->cheapest = true;
}

void	init_list_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
