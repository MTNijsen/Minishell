/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:45:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 17:35:48 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_procs(t_data *data)
{
	t_token	*current_token;
	t_proc	*new_proc;

	current_token = data->tokens;
	// printf("%p\n", data->tokens);
	// printf("VALUE CURRENT: %s\n", current_token->value);
	while (current_token)
	{
		new_proc = create_proc(current_token);
		while (current_token && current_token->type != PIPE)
			current_token = current_token->next;
		add_proc(data, new_proc);
		if (current_token && current_token->type == PIPE)
			current_token = current_token->next;
	}
	return (0);
}
