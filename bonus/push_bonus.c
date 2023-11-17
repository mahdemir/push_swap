/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 13:16:05 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 15:07:55 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/checker.h"

static void	push_bonus(t_stack **dst, t_stack **src)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *dst;
	*dst = *src;
	*(src) = (*src)->next;
	(*dst)->next = tmp;
}

void	pa_bonus(t_stack **a, t_stack **b)
{
	push_bonus(a, b);
}

void	pb_bonus(t_stack **b, t_stack **a)
{
	push_bonus(b, a);
}
