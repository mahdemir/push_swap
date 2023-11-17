/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 10:21:32 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 15:07:39 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/checker.h"

static void	swap_bonus(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa_bonus(t_stack **a)
{
	swap_bonus(a);
}

void	sb_bonus(t_stack **b)
{
	swap_bonus(b);
}

void	ss_bonus(t_stack **a, t_stack **b)
{
	swap_bonus(a);
	swap_bonus(b);
}
