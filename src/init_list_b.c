/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_list_b.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 03:10:33 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:59:36 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack *stack_a, t_stack *b)
{
	t_stack	*a;
	t_stack	*target;
	long	best_match;

	while (b)
	{
		best_match = MAX;
		a = stack_a;
		while (a)
		{
			if (a->num > b->num && a->num < best_match)
			{
				best_match = a->num;
				target = a;
			}
			a = a->next;
		}
		if (best_match == MAX)
			b->target = find_min(stack_a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_list_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target_b(a, b);
}
