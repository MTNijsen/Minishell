/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 12:58:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 14:43:21 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function could use some cleaning up and maybe exit codes etc.
// Also needs cleaning up stuff.
void	ft_error(t_data *data, int flag)
{
	free_struct(data);
	if (flag == -1)
		ft_puterror_fd("Malloc error", STDERR_FILENO);
	else if (flag == -2)
		ft_puterror_fd("Syntax error", STDERR_FILENO);
}