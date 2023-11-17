/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 21:25:34 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:47:36 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *compare)
{
	if (!*a || !*b || !compare)
		return ;
	while (*a != compare && *b != compare->target)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *compare)
{
	if (!*a || !*b || !compare)
		return ;
	while (*a != compare && *b != compare->target)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

static void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	if (!*a || !*b)
		return ;
	cheapest = find_cheapest(*a);
	if (cheapest->above_middle && cheapest->target->above_middle)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_middle) && !(cheapest->target->above_middle))
		rev_rotate_both(a, b, cheapest);
	prep_stack(a, cheapest, 'a');
	prep_stack(b, cheapest->target, 'b');
	pb(b, a);
}

static void	push_to_a(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	prep_stack(a, (*b)->target, 'a');
	pa(a, b);
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	len_a;

	if (!*a)
		return ;
	len_a = stack_len(*a);
	if (len_a-- > 3 && check_sort(*a) == false)
		pb(b, a);
	if (len_a-- > 3 && check_sort(*a) == false)
		pb(b, a);
	while (len_a-- > 3 && check_sort(*a) == false)
	{
		init_list_a(*a, *b);
		push_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_list_b(*a, *b);
		push_to_a(a, b);
	}
	set_index(*a);
	double_check(a);
}
