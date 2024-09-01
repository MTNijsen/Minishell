/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 13:05:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 13:58:28 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_struct(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->procs = NULL;
	data->tokens = NULL;
	data->envp = NULL;
	data->input = NULL;
	return (data);
}
