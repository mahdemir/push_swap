/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/17 11:25:47 by mademir       #+#    #+#                 */
/*   Updated: 2023/12/03 09:01:21 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	err_msg_bonus(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}

void	check_command_tripple(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		rra_bonus(a);
	else if (line[2] == 'b')
		rrb_bonus(b);
	else if (line[2] == 'r')
		rrr_bonus(a, b);
}

char	*check_command(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa_bonus(a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb_bonus(b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		pa_bonus(a, b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		pb_bonus(b, a);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra_bonus(a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb_bonus(b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_command_tripple(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr_bonus(a, b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss_bonus(a, b);
	else
		err_msg_bonus("Error");
	return (get_next_line(STDIN_FILENO));
}

void	checker(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = check_command(a, b, line);
		free(tmp);
	}
	if (*b)
	{
		write(1, "KO\n", 3);
	}
	else if (check_sort_bonus(*a) == false)
	{
		write(1, "KO\n", 3);
	}
	else
	{
		write(1, "OK\n", 3);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	check_args_bonus(argc, argv);
	init_stack_bonus(&a, argc, argv);
	line = get_next_line(STDIN_FILENO);
	if (!line && check_sort_bonus(a) == false)
	{
		write(1, "KO\n", 3);
	}
	else if (!line && check_sort_bonus(a) == true)
		write(1, "OK\n", 3);
	else
		checker(&a, &b, line);
	return (0);
}
