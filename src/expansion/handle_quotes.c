/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/07 15:53:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (1);
		i++;
	}
	return (0);
}

int	check_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}
int	is_quote(int q)
{
	if (q == '\"')
		return (1);
	else if (q == '\'')
		return (1);
	return (0);
}

void	no_quote_cpy_loop(char *str, char *new, int *i, int *j)
{
	while (str[(*i)] && !is_quote(str[(*i)]))
	{
		new[(*j)] = str[(*i)];
		(*i)++;
		(*j)++;
	}
}

void	quote_cpy_loop(char *str, char *new, int *i, int *j)
{
	int		q;

	q = str[(*i)];
	(*i)++;
	while (str[(*i)] && str[(*i)] != q)
	{
		new[(*j)] = str[(*i)];
		(*i)++;
		(*j)++;
	}
	if (str[(*i)] == q)
	{
		q = 0;
		(*i)++;
	}
	if (q != 0)
	{
		printf("Syntax ERROR!\n");
		return ;
	}
}

char	*remove_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		no_quote_cpy_loop(str, new, &i, &j);
		if (is_quote(str[i]))
			quote_cpy_loop(str, new, &i, &j);
	}
	return (new);
}

void	handle_str(t_proc *proc)
{ 
	int		i;
	char	**str;

	str = (char **)ft_calloc((proc->argc + 1), sizeof(char *));
	i = 0;
	while (proc->argv[i])
	{
		str[i] = ft_strdup(proc->argv[i]);
		// if (!str[i])
		// 	exit;
		i++;
	}
	ft_free_arr(proc->argv);
	proc->argv = (char **)ft_calloc((proc->argc + 1), sizeof(char *));
	i = 0;
	proc->argv[i] = ft_strdup(str[i]);
	i++;
	while (str[i])
	{
		if (check_quotes(str[i]) && !check_dollar(str[i]))
			proc->argv[i] = remove_quotes(str[i]);
		else
			proc->argv[i] = ft_strdup(str[i]);
		i++;
	}
}

void	handle_cmd(t_proc *proc)
{
	char	*str;

	str = ft_strdup(proc->argv[0]);
//	if (!str)
//		exit;
	free(proc->argv[0]);
		if (!check_spaces(str) && !check_dollar(str))
			proc->argv[0] = remove_quotes(str);
		else if (check_spaces(str))
			printf("Syntax error!\n");
}

/**
 * @brief	if the cmd has quotes, there has to be a check if there are
 * 			spaces, if so cmd is invalid (this will be checked in )
 */
void	handle_quotes(t_data *data)
{
	t_proc	*proc;

	proc = data->procs;
	while (proc != NULL)
	{
		if (proc->argv[0] && check_quotes(proc->argv[0]))
			handle_cmd(proc);
		if (proc->argv)
			handle_str(proc);
		proc = proc->next;
	}
}
