/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:28 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 18:08:00 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_exit(char **argv, t_data *data, bool pipe_present)
{
	if (pipe_present == false)
		write(1, "exit\n", 5);
	if (argv[1] != NULL)
		clean_exit(data, ft_atoi(argv[1]));
	clean_exit(data, 0);
}
