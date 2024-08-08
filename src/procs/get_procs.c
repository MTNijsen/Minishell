/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 16:31:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_procs(t_proc **procs, t_token **tokens)
{
	t_token	*current_token;
	t_proc	*proc;

	current_token = *tokens;
	proc = init_proc();
	while (current_token)
	{
		if (current_token->type == PIPE)
		{
			add_proc(procs, proc);
			current_token = current_token->next;
		}
	}
	return (true);
}