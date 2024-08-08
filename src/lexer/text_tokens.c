/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 19:27:31 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	reclassify_text_token(t_token **head, int flag)
{
	t_token	*current;
	t_token	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		if (current->type == PIPE)
			flag = 1;
		if (next && current->type > 1 && current->type < 6 && next->type == TEXT)
			next->type = FILES;
		else if (!next  && current->type > 1 && current->type < 6)
			return (-1); //should return syntax error instead
		else if (current->type == TEXT && flag == 1)
		{
			current->type = COMMAND;
			flag = 0;
		}
		else if (current->type == TEXT)
			current->type = STRING;
		current = next;
	}
	return (0);
}

int	create_text_token(t_token **head, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	while (input[i] && !ft_isspecial(input[i], " |<>\"\'"))
		i++;
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(head, token);
	free (value);
	return (i);
}

int	create_quotes_token(t_token **head, char *input, int i)
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
	add_token(head, token);
	free (value);
	return (i);
}

int	text_tokens(t_token **head, char *input, int i)
{
	int	x;

	x = 0;
	if (input[i] == '\"' || input[i] == '\'')
		x = create_quotes_token(head, input, i);
	else
		x = create_text_token(head, input, i);
	return (x);
}
