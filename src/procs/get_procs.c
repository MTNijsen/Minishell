/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:45:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 16:55:05 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_procs(t_data *data)
{
	t_token	*current_token;
	t_proc	*new_proc;

	new_proc = init_proc();
	if (!new_proc)
		return (-1);
	data->token_count = count_tokens(&data->tokens);
	data->proc_count = count_procs(&data->tokens);
	current_token = data->tokens;
	while (current_token)
	{
		new_proc = create_proc(current_token);
		while (current_token->type != PIPE)
			current_token = current_token->next;
		if (current_token->type == PIPE)
		{
			add_proc(data, new_proc);
			current_token = current_token->next; 
		}
	}
	return (0);
}
