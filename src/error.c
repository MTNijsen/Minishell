/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 12:58:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 20:59:20 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_data *data, int flag)
{
	if (flag == MALLOC_ERROR)
	{
		ft_puterror_fd("Malloc error", STDERR_FILENO);
		clean_exit(data, MALLOC_ERROR);
	}
	else if (flag == SYNTAX_ERROR)
	{
		ft_puterror_fd("Syntax error", STDERR_FILENO);
		free_data(data);
	}
}
