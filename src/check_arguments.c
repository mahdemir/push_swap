/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 14:34:27 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/11 17:33:57 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_dup(long num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	int		i;
	long	tmp;

	i = 1;
	while (argv[i])
	{
		if (!isnum)
			err_msg("Error");
		tmp = ft_atol(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			err_msg("Error");
		if (check_dup(tmp, argv, i))
			err_msg("Error");
		i++;
	}
}
