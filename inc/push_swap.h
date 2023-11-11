/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mademir <mademir@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 10:26:25 by mademir       #+#    #+#                 */
/*   Updated: 2023/11/11 14:34:09 by mademir       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SPAP_H
# define PUSH_SWAP_H

/********** LIBRARIES *********************************************************/

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

/********** STRUCTS ***********************************************************/

typedef	struct s_stack
{
	int				num;
	int				index;
	int				price;
	bool			top_half;
	bool			cheapest;

	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
	
}					t_stack;

/********** PROTOTYPES ********************************************************/

void	err_msg(char *msg);
void	check_args(int argc, char **argv);

#endif