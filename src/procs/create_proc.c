/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 16:53:38 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir(t_proc *procs, t_token **tokens)
{
	t_token	*current;

	current = *tokens;
}

char	*get_command(t_data *data)
{

}

t_proc	*create_proc(t_token *token)
{
	t_token	*current_token;
	t_proc	*proc;

	proc = init_proc();
	current_token = token;
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
