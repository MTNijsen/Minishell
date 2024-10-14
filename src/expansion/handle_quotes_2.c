/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 17:34:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 16:02:56 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	no_quote_cpy_loop(char *str, char *new, int *i, int *j)
{
	while (str[(*i)] && !is_quote(str[(*i)]))
	{
		new[(*j)] = str[(*i)];
		(*i)++;
		(*j)++;
	}
}

static int	quote_cpy_loop(char *str, char *new, int *i, int *j)
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
		return (SYNTAX_ERROR);
	return (SUCCESS);
}

char	*remove_quotes(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		x;

	new = (char *)ft_calloc(sizeof(char), (ft_strlen(str) - 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	if (!str || ft_strlen(str) == 0)
		return (ft_strdup("\n"));
	while (str[i])
	{
		no_quote_cpy_loop(str, new, &i, &j);
		if (is_quote(str[i]))
			x = quote_cpy_loop(str, new, &i, &j);
		if (x == SYNTAX_ERROR)
		{
			free(new);
			return (NULL);
		}
	}
	return (new);
}
