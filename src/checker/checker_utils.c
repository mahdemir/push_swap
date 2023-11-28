/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 12:33:14 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/27 14:13:36 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

bool	check_sort_bonus(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_last_bonus(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

static void	add_to_stack_bonus(t_stack **stack, int num)
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
		last = find_last_bonus(*stack);
		last->next = new;
		new->prev = last;
	}
}

void	init_stack_bonus(t_stack **stack, int argc, char **argv)
{
	int	i;
	int	num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		add_to_stack_bonus(stack, num);
		i++;
	}
}
