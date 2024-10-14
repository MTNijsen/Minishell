/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 12:58:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 14:49:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_error(t_data *data, int flag)
{
	if (flag == MALLOC_ERROR)
	{
		printf("Malloc error\n");
		clean_exit(data, MALLOC_ERROR);
	}
	else if (flag == SYNTAX_ERROR)
		printf("Syntax error\n");
	return (flag);
}
