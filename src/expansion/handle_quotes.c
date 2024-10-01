/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/01 16:27:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_quotes(char *str)
{

}

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

void	handle_quotes(t_data *data)
{
	if (data->procs->argv[0] && check_quotes(data->procs->argv[0]))
	{
		if (!check_spaces(data->procs->argv[0]) && !check_dollar(data->procs->argv[0]))
			remove_quotes(data->procs->argv[0]);
	}
}
