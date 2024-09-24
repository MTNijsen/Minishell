/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 14:40:01 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/24 18:20:17 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_data(t_data *data)
{
	if (data->tokens)
		free_tokens(&data->tokens);
	if (data->procs)
		free_procs(&data->procs);
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
}

void	free_data(t_data *data)
{
	clean_data(data);
	ft_free_arr(data->envp);
}
