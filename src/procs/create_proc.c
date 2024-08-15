/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:10:22 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redirects(t_token *token)
{
	t_token	*current;

	current = token;
	return (0);
}

char	**get_arguments(t_token *token)
{
	
}

char	*get_command(t_token *token)
{
	if (token)
		return (NULL);
	return (NULL);
}

t_proc	*create_proc(t_data *data)
{
	t_token	*current_token;
	t_proc	*proc;

	proc = init_proc();
	current_token = data->tokens;
	data->procs->cmd = get_command(current_token);
	data->procs->argv = get_arguments(current_token);
	data->procs->redirs = get_redirects(current_token);
	data->procs->token_count = count_tokens_proc(current_token);
	return (proc);
}
