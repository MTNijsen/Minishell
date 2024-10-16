/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:45:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/16 15:06:43 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_procs(t_data *data)
{
	t_token	*current_token;
	t_proc	*new_proc;

	current_token = data->tokens;
	while (current_token)
	{
		new_proc = create_proc(current_token);
		if (!new_proc)
			ft_error(data, MALLOC_ERROR);
		while (current_token && current_token->type != PIPE)
			current_token = current_token->next;
		add_proc(data, new_proc);
		if (current_token && current_token->type == PIPE)
			current_token = current_token->next;
	}
	return (0);
}
