/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_proc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:07:29 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/29 18:03:20 by lade-kon      ########   odam.nl         */
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
t_proc	*create_proc(t_data *data, t_token *token, int proc_number)
{
	t_token	*current;
	t_proc	*proc;
	int		i;

	proc = init_proc(token);
	if (!proc)
		return (NULL);
	current = token;
	proc->argc = count_arguments(current);
	if (proc->argc != 0)
		proc->argv = (char **)malloc((proc->argc + 1) * sizeof(char *));
	if (!proc->argv)
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
		if (is_redirect(current) == true)
		{

		}
		current = current->next;
	}
	get_redirects(data, current);
	proc->index = proc_number;
	return (proc);
}
