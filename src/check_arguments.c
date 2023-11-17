/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 14:34:27 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/17 11:03:43 by mademir       ########   odam.nl         */
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

void	check_args(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!check_num(argv[i]))
			err_msg("Error");
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			err_msg("Error");
		if (check_dup(argv, num, i))
			err_msg("Error");
		i++;
	}
}
