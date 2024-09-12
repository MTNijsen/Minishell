/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 13:05:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 18:24:42 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*init_struct(char **env)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->procs = NULL;
	data->tokens = NULL;
	copy_array(&(data->envp), env);
	data->input = NULL;
	// printf("init_struct data_token: %p\n", data->tokens);
	return (data);
}
