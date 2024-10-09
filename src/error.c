/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 12:58:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/07 17:50:30 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function could use some cleaning up and maybe exit codes etc.
// Also needs cleaning up stuff.
void	ft_error(t_data *data, int flag)
{
	if (flag < 0)
	{
		if (flag == -1)
		{
			ft_puterror_fd("Malloc error", STDERR_FILENO);
			free_data(data);
		}
		else if (flag == -2)
			write(STDERR_FILENO, "Syntax error\n", 14);
	}
	else
		return ;
}
