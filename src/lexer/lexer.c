/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 20:39:05 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_last_quote(char *input, int i)
{
	int len;

	while (input[i])
	{
		i++;
		if (input[i] == '\"')
			return (i);
	}
	return (0);
}

bool	ft_lexer(t_token **token_lst, char *input)
{
	int	i;
	int	len;

	while (input[i] == ' ')
		i++;
	if (input[i] == '|')
	{
		create_token(PIPE, '|');
		i++;
	}
	else if (input[i] == '>')
	{
		create_token(IN_REDIRECT, '>');
		i++;
	}
	else if (input[i] == '<')
	{
		create_token(OUT_REDIRECT, '<');
		i++;
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		create_token(APP_REDIRECT, '>>');
		i++;
	}
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		create_token(HEREDOC, '<<');
		i++;
	}
	else if (input[i] == '\"')
	{
		len = find_last_quote(input, i);
	}
	return (true);
}
