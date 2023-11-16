/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 21:25:34 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/16 17:02:56 by mademir       ########   odam.nl         */
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

/* Calculate how many command needed to get node
** in a and target node in b at top of the stacks */
void	calculateCost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stackLen(a);
	len_b = stackLen(b);
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

void	setCheapest(t_stack *stack)
{
	int		cheapest;
	t_stack	*tmp;

	if (!stack)
		return ;
	cheapest = LONG_MAX;
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

void	initList_a(t_stack *a, t_stack *b)
{
	setIndex(a);
	setIndex(b);
	setTarget_a(a, b);
	calculateCost(a, b);
}

void	rotateBoth(t_stack **a, t_stack **b, t_stack *compare)
{
	while (*a != compare && *b != compare->target)
		rr(a, b, true);
	setIndex(*a);
	setIndex(*b);
}

void	revRotateBoth(t_stack **a, t_stack **b, t_stack *compare)
{
	while (*a != compare && *b != compare->target)
		rrr(a, b, true);
	setIndex(*a);
	setIndex(*b);
}

void	pushToB(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!*a || !*b)
		return ;
	cheapest = findCheapest(*a);
	if (cheapest->above_middle && cheapest->target->above_middle)
	{
		rotateBoth(a, b, cheapest);
	}
	else if (!(cheapest->above_middle && cheapest->target->above_middle))
	{
		revRotateBoth(a, b, cheapest);
	}
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
		pushToB(a, b);
	}
}
