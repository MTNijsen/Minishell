/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 17:02:30 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reclassify_text_token(t_token **head);
{
	t_token	*current;

	current = *head;
	if (current->type == TEXT)
	{
		
	}
}

int	create_word_token(t_token **head, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	while (input[i] && !ft_isspecial(input[i], " |<>\"\'"))
		i++;
	value = ft_substr(input, start, (i - start));
	token = create_token(STRING, value);
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

int	create_text_token(t_token **head, char *input, int i)
{
	int	x;

	x = 0;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			x = create_quotes_token(head, input, i);
			break ;
		}
		else
		{
			x = create_word_token(head, input, i);
			break ;
		}
	}
	return (x);
}
