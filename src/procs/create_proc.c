/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 21:16:01 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_arguments(t_token *token)
{
	t_token	*current;
	int		count;

	current = token;
	count = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == STRING || current->type == COMMAND)
			count++;
		current = current->next;
	}
	return (count);
}

static bool	allocate_proc_argv(t_proc *proc)
{
	if (proc->argc != 0)
	{
		proc->argv = (char **)ft_calloc((proc->argc + 1), sizeof(char *));
		if (!proc->argv)
			return (false);
	}
	return (true);
}

static void	process_tokens(t_proc *proc, t_token *current)
{
	t_token	*new_redir;
	int		i;

	i = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == COMMAND)
		{
			proc->cmd = ft_strdup(current->value);
			proc->argv[i] = proc->cmd;
			i++;
		}
		else if (current->type == STRING)
		{
			proc->argv[i] = ft_strdup(current->value);
			i++;
		}
		else if (is_redirect(current) == true)
		{
			new_redir = create_token(current->type, current->next->value);
			add_redir(&proc->redirs, new_redir);
			current = current->next;
		}
		current = current->next;
	}
}

/**
* @brief	this function needs the complete data struct and also
*			a pointer to the current token so it knows which process
*			its working on. 
*/
t_proc	*create_proc(t_token *token)
{
	t_token	*current;
	t_proc	*proc;

	proc = init_proc();
	if (!proc)
		return (NULL);
	current = token;
	proc->argc = count_arguments(current);
	if (!allocate_proc_argv(proc));
		return (NULL);
	process_tokens(proc, current);
	return (proc);
}
