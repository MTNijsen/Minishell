/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_input_check.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/04 12:25:12 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	last_check(t_data *data)
{
	if (check_spaces(data->procs->argv[0]))
		return ("Syntax error");
	
}
