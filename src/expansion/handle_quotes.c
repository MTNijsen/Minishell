/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/01 20:54:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == " ")
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
		if (str[i] == "$")
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
		if (str[i] == "\"" || str[i] == "\'")
			return (1);
		i++;
	}
	return (0);
}
int	type_quote(int q)
{
	if (q == "\"")
		return ("\"")
	else if (q = "\'")
		return ("\'")
	return (0);
}

void	no_quote_cpy_loop(char *str, char *new, int *i, int *j, int q)
{
	if (q = 0)
	{
		while (str[(*i)] && !is_quote(str[(*i)]))
		{
			new[(*j)] = str[(*i)];
			(*i)++;
			(*j)++;
		}
	}
	else
	{
		while (str[(*i)] && str[(*i)]  != q)
		{
			new[(*j)] = str[(*i)];
			(*i)++;
			(*j)++;
		}
	}
}

void	remove_quotes(char *str)
{
	char	*new;
	int		q;
	int		i;
	int		j;

	new = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - 1));
	i = 0;
	j = 0;
	q = 0;
	while (str[i])
	{
		no_quote_cpy_loop(str, new, &i, &j, q)
		if (is_quote(str[i]))
		{
			q = str[i];
			while ()
		}
		
	}

	q = type_quote(str[i]);

}

void	handle_quotes(t_data *data)
{
	if (data->procs->argv[0] && check_quotes(data->procs->argv[0]))
	{
		if (!check_spaces(data->procs->argv[0]) && !check_dollar(data->procs->argv[0]))
			remove_quotes(data->procs->argv[0]);
	}
}
