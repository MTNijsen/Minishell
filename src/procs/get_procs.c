/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 18:44:34 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir(t_proc *procs, t_token **tokens)
{
	t_token	*current;

	current = *tokens;
}

bool	get_procs(t_proc **procs, t_token **tokens)
{
	t_token	*current_token;
	t_proc	*proc;

	current_token = *tokens;
	proc = init_proc();
	while (current_token)
	{
		while (current_token->type != PIPE)
		{
			
		}
		if (current_token->type == PIPE)
			add_proc(procs, proc);
		current_token = current_token->next;
	}
	return (true);
}