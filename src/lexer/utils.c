/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:18:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/01 21:35:56 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isspecial(char input, const char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (input == check[i])
			return (true);
		i++;
	}
	return (false);
}

int	handle_quotes(char *input, int i)
{
	int		end_quote;
	char	quote;

	quote = input[i];
	end_quote = false;
	while (input[i] && input[i + 1] && end_quote == false)
	{
		i++;
		if (input[i] == quote)
			end_quote = true;
	}
	if (end_quote == false)
		return (-1);
	return (i + 1);
}
