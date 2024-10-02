/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/02 21:14:20 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "test.h"

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
	i++;
	while (str[(*i)] && str[(*i)]  != q)
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
		printf("Syntax ERROR!\n");
}

char	*remove_quotes(char *str)
{
	char	*new;
	char	*result;
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
	result = ft_strdup(new);
	return (result);
}

char	*handle_quotes(char *str)
{
	char *result;

	if (str && check_quotes(str))
	{
		if (!check_spaces(str) && !check_dollar(str))
			result = remove_quotes(str);
		else
			printf("Komt niet in remove_quotes\n");
	}
	return (result);
}

// void	handle_quotes(t_data *data)
// {
// 	if (data->procs->argv[0] && check_quotes(data->procs->argv[0]))
// 	{
// 		if (!check_spaces(data->procs->argv[0]) && !check_dollar(data->procs->argv[0]))
// 			remove_quotes(data->procs->argv[0]);
// 	}
// }
