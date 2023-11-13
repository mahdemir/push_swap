/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/12 06:16:24 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/13 11:39:14 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	addToStack(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->num = num;
	if (!(*stack))
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = findLast(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	initStack(t_stack **stack, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		addToStack(stack, num);
		i++;
	}
}
