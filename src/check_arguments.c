/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 14:34:27 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/13 14:45:11 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	check_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_dup(char **argv, long num, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (true);
		i++;
	}
	return (false);
}

void	checkArgs(char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (argv[i])
	{
		if (!check_num(argv[i]))
			errMsg("Error");
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			errMsg("Error");
		if (check_dup(argv, num, i))
			errMsg("Error");
		i++;
	}
}
