/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/15 21:03:50 by lade-kon      ########   odam.nl         */
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
		return (-1);
	return (i + 1);
}

// int	create_text_token(t_data *data, char *input, int i)
// {
// 	t_token	*token;
// 	int		start;
// 	char	*value;

// 	start = i;
// 	value = NULL;
// 	if(is_quote(input[i]) == 1)
// 		i = find_end_quote(input, i);
// 	else
// 	{
// 		while (input[i] && !is_special(input[i], " |<>"))
// 			i++;
// 	}
// 	value = ft_substr(input, start, (i - start));
// 	token = create_token(TEXT, value);
// 	if (token == NULL || value == NULL)
// 		return (-1);
// 	add_token(data, token);
// 	free (value);
// 	return (i);
// }

int	text_no_quotes_token(t_data *data, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	while (input[i] && !is_special(input[i], " |<>\"\'"))
		i++;
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}

int	text_with_quotes_token(t_data *data, char *input, int i)
{
	t_token	*token;
	int		x;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	x = find_end_quote(input, i);
	value = ft_substr(input, (start), (x - start));
	printf("VALUE = %s\n", value);
	i = x;
	token = create_token(STRING, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}

int	create_text_token(t_data *data, char *input, int i)
{
	int	x;

	x = 0;
	if (input[i] == '\"' || input[i] == '\'')
		x = text_with_quotes_token(data, input, i);
	else
		x = text_no_quotes_token(data, input, i);
	return (x);
}
