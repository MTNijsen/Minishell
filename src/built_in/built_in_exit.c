/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:28 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 17:34:21 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_exit(char **argv, t_data *data, bool pipe_present)
{
	if (argv[1] != NULL && !ft_isnumber(argv[1]))
	{
		write(2, "exit: numeric argument required\n", 33);
		return (255);
	}
	if (argv[1] != NULL && argv[2] != NULL)
	{
		write(2 , "exit: too many arguments\n", 26);
		return (1);
	}
	if (pipe_present == false)
		write(1, "exit\n", 5);
	if (argv[1] != NULL)
		clean_exit(data, ft_atoi(argv[1]));
	clean_exit(data, 0);
	return (0);
}
