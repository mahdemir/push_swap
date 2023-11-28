/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 20:33:26 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 14:46:22 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	if (!a)
		return ;
	max = find_max(*a);
	if ((*a)->num == max->num)
		ra(a);
	else if ((*a)->next->num == max->num)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}
