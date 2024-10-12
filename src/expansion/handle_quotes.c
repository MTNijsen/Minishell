/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/12 16:28:59 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**prepare_2d_arr(t_data *data, t_proc *proc)
{
	char	**cpy_argv;
	int		i;

	cpy_argv = (char **)ft_calloc((proc->argc + 1), sizeof(char *));
	if (!cpy_argv)
		clean_exit(data, MALLOC_ERROR);
	i = 0;
	while (proc->argv[i])
	{
		cpy_argv[i] = ft_strdup(proc->argv[i]);
		if (!cpy_argv[i])
			clean_exit(data, MALLOC_ERROR);
		i++;
	}
	ft_free_arr(proc->argv);
	proc->argv = (char **)ft_calloc((proc->argc + 1), sizeof(char *));
	if (!proc->argv)
		clean_exit(data, MALLOC_ERROR);
	proc->argv[0] = ft_strdup(cpy_argv[0]);
	if (!cpy_argv[0])
		clean_exit(data, MALLOC_ERROR);
	return (cpy_argv);
}

int	handle_str(t_data *data, t_proc *proc)
{
	int		i;
	char	**str;

	str = prepare_2d_arr(data, proc);
	i = 1;
	while (str[i])
	{
		if (check_quotes(str[i]))
		{
			proc->argv[i] = remove_quotes(str[i]);
			if (proc->argv[i] == NULL)
				return (SYNTAX_ERROR);
		}
		else
			proc->argv[i] = ft_strdup(str[i]);
		if (!str[i])
			clean_exit(data, MALLOC_ERROR);
		i++;
	}
	return (SUCCESS);
}

int	handle_cmd(t_data *data, t_proc *proc)
{
	char	*str;

	str = ft_strdup(proc->argv[0]);
	if (!str)
		clean_exit(data, MALLOC_ERROR);
	free(proc->argv[0]);
	proc->argv[0] = NULL;
	if (!check_spaces(str))
		proc->argv[0] = remove_quotes(str);
	if (check_spaces(str) || proc->argv[0] == NULL)
		return (SYNTAX_ERROR);
	return (SUCCESS);
}

/**
 * @brief	if the cmd has quotes, there has to be a check if there are
 * 			spaces, if so cmd is invalid (this will be checked in )
 */
int	handle_quotes(t_data *data)
{
	t_proc	*proc;
	int		x;

	proc = data->procs;
	while (proc != NULL)
	{
		if (proc->argv[0] && check_quotes(proc->argv[0]))
			x = handle_cmd(data, proc);
		if (proc->argv)
			x = handle_str(data, proc);
		if (x == SYNTAX_ERROR)
			return (SYNTAX_ERROR);
		proc = proc->next;
	}
	return (SUCCESS);
}
