/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 14:40:01 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 21:25:19 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_struct(t_data *data)
{
	if (data)
	{
		// if (data->tokens)
		// 	free_tokens(&data->tokens);
		// if (data->procs)
		// 	free_procs(&data->procs);
		// if (data ->envp)
		// 	ft_free_arr(data->envp);
		if (data->input)
			free(data->input);
			data->input = NULL;
		}
	}
}

void	free_data(t_data *data)
{
	if (data)
	{
		free_struct(data);
		ft_free_arr(data->envp);
		free(data);
	}
}
