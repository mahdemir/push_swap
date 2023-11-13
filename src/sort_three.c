/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_three.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 20:33:26 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/13 14:43:05 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortThree(t_stack **a)
{
	t_stack	*max;

	if (!a)
		return ;
	max = findMax(*a);
	if ((*a)->num == max->num)
		ra(a, true);
	else if ((*a)->next->num == max->num)
		rra(a, true);
	if ((*a)->num > (*a)->next->num)
		sa(a, true);
}
