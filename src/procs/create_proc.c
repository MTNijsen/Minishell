/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 18:45:15 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	count_tokens_proc(t_data *data, t_token *token)
{
	t_token	*current;
	int		count;

	count = 0;
	current = token;
	while (current && current->type != PIPE)
	{
		count++;
		current = current->next;
	}
	data->procs->token_count = count;
}

static void	get_redirects(t_data *data, t_token *token)
{
	t_token	*current;
	t_redir	*redir;

	current = token;
	while (current && current->type != PIPE)
	{
		if (is_redirect(current))
		{
			redir = create_redir(current->type, current->next->value);
			add_redir(data, redir);
			current = current->next;
		}
		current = current->next;
	}
	return ;
}

static void	get_arguments(t_data *data, t_token *token)
{
	t_token	*current;
	int		argc;

	current = token;
	argc = count_arguments(current);
	data->procs->argv = (char **)malloc((argc + 1) * sizeof(char *));
	if (!data->procs->argv)
		return ; //should be exiting program and cleaning everything.
	while (current && current->type != PIPE)
	{
		if (current->type == STRING)
		{
			
		}
	}
}

static void	get_command(t_data *data, t_token *token)
{
	if (token)
		return (NULL);
	return (NULL);
}
/**
* @brief	this function needs the complete data struct and also
*			a pointer to the current token so it knows which process
*			its working on. 
*/
t_proc	*create_proc(t_data *data, t_token *token, int proc)
{
	t_token	*current_token;
	t_proc	*proc;

	proc = init_proc();
	current_token = token;
	get_command(data, current_token);
	get_arguments(data, current_token);
	get_redirects(data, current_token);
	proc.token_count = count_tokens_proc(current_token);
	return (proc);
}
