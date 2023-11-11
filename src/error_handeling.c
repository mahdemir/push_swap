/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handeling.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 14:28:48 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/11 14:33:21 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_msg(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}
