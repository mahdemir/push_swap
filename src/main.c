/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 11:20:41 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/16 00:48:46 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	checkArgs(argv);
	initStack(&a, argc, argv);
	if (!checkSort(a))
	{
		if (stackLen(a) == 2)
			sa(&a, true);
		else if (stackLen(a) == 3)
			sortThree(&a);
		else
			sortAlgorithm(&a, &b);
	}

	return (0);
}
