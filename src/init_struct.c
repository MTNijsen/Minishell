/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 13:05:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 13:31:39 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data, char **env)
{
	int		i;
	
	data->procs = NULL;
	data->tokens = NULL;
	copy_array(&(data->envp), env);
	i = 0;
	while (env[i])
		i++;
	data->envp_count = i;
	data->input = NULL;
	data->exit_code = 0;
	dup2(STDIN_FILENO, STDIN_CLONE);
	dup2(STDOUT_FILENO, STDOUT_CLONE);
	set_sig(S_INTERACTIVE);
}
