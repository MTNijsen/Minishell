/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 17:14:07 by lade-kon      ########   odam.nl         */
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

/**
* @brief	this function needs the complete data struct and also
*			a pointer to the current token so it knows which process
*			its working on. 
*/

t_proc	*create_proc(t_data *data, t_token *token, t_count *counter)
{
	t_token	*current;
	t_token	*new_redir;
	t_proc	*proc;
	int		i;

	proc = init_proc(token, counter);
	if (!proc)
		return (NULL);
	current = token;
	counter->argv_c = count_arguments(current);
	if (counter->argv_c != 0)
		proc->argv = (char **)malloc((counter->argv_c + 1) * sizeof(char *));
	if (!proc->argv)
		return (NULL); //have to check if this is correct
	i = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == COMMAND)
			proc->cmd = ft_strdup(current->value);
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
	return (proc);
}
