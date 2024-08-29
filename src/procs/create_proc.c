/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/29 17:20:23 by lade-kon      ########   odam.nl         */
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
		printf("value of current: %s\n", current->value);
		if (current->type == STRING)
			count++;
		current = current->next;
	}
	printf("count: %i\n", count);
	return (count);
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

static char	**get_arguments(t_data *data, t_token *token)
{
	t_token	*current;
	char	**argv;
	int		argc;
	int		i;
	int		len;
	
	if (token)
	{
		current = token;
		argc = count_arguments(current);
		printf("argc: %i\n", argc);
		argv = (char **)malloc((count_arguments(current) + 1) * sizeof(char *));
		if (!argv)
		{
			data->token_count = 0;
			return (NULL); //should be exiting program and cleaning everything.
		}
		i = 0;
		while (current && current->type != PIPE && i < argc)
		{
			if (current->type == STRING)
			{
				len = ft_strlen(current->value);
				argv[i] = ft_substr(current->value, 0, (len + 1));
				i++;
			}
			current = current->next;
		}
		return (argv);
	}
	return (NULL);
}

static char	*get_command(t_token *token)
{
	t_token	*current;

	current = token;
	while (current && current->type != PIPE)
	{
		if (current->type == COMMAND)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
/**
* @brief	this function needs the complete data struct and also
*			a pointer to the current token so it knows which process
*			its working on. 
*/
t_proc	*create_proc(t_data *data, t_token *token, int proc_number)
{
	t_token	*current;
	t_proc	*proc;
	int		i;

	proc = init_proc();
	if (!proc)
		return (NULL);
	current = token;
	proc->argc = count_arguments(current);
	if (proc->argc != 0)
		proc->argv = (char **)malloc((proc->argc + 1) * sizeof(char *));
		if (!proc->argv)
			return (NULL); //have to check if this is correct
	proc->redirc = count_redirs_proc(current);
	if (proc->redirc != 0)
		proc->redirs = (char **)malloc((proc->redirc + 1) * sizeof(char *));
		if (!proc->redirs)
			return (NULL); //have to check if this is correct
	i = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == COMMAND)
			proc->cmd = ft_strdup(current->value);
		if (current->type == STRING)
		{
			proc->argv[i] = ft_strdup(current->value);
			i++;
		}
		if (is_redirect(current->type) == true)
		{

		}
		current = current->next;
	}
	get_redirects(data, current);
	proc->index = proc_number;
	return (proc);
}
