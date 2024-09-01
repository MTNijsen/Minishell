/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/29 17:11:01 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reclassify_text_token(t_data *data, int flag)
{
	t_token	*token;
	t_token	*next;

	token = data->tokens;
	while (token)
	{
		next = token->next;
		if (token->type == PIPE)
			flag = 1;
		if (next && is_redirect(token) && next->type == TEXT)
			next->type = FILES;
		else if (token->type == TEXT && flag == 1)
		{
			token->type = COMMAND;
			flag = 0;
		}
		else if (token->type == TEXT)
			token->type = STRING;
		token = next;
	}
}

int	create_text_token(t_data *data, char *input, int i)
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

int	create_quotes_token(t_data *data, char *input, int i)
{
	t_token	*token;
	int		x;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	x = handle_quotes(input, i);
	value = ft_substr(input, (start), (x - start));
	i = x;
	token = create_token(STRING, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}

int	text_tokens(t_data *data, char *input, int i)
{
	int	x;

	x = 0;
	if (input[i] == '\"' || input[i] == '\'')
		x = create_quotes_token(data, input, i);
	else
		x = create_text_token(data, input, i);
	return (x);
}
