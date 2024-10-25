/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/25 11:57:22 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_end_quote(char *input, int i)
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
		return (SYNTAX_ERROR);
	return (i + 1);
}

int	create_text_token(t_data *data, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;
	int		x;

	start = i;
	value = NULL;
	while (input[i] && !is_special(input[i], " |<>"))
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			if ((x = find_end_quote(input, i)) == SYNTAX_ERROR)
				return (SYNTAX_ERROR);
			i = x;
			break ;
		}
		i++;
	}
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}
