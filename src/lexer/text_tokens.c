/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 20:15:56 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reclassify_text_token(t_token **head, int flag)
{
	t_token	*current;

	current = *head;
	while (current && current->next)
	{
		if (current->type == PIPE)
			flag = 1;
		if (current->type == IN_REDIRECT && current->next->type == TEXT)
			current->next->type = OUT_FILE;
		else if (current->type == OUT_REDIRECT && current->next->type == TEXT)
			current->next->type = IN_FILE;
		else if (current->type == HEREDOC && current->next->type == TEXT)	
			current->next->type = DELIMITER;
		else if (current->type == APP_REDIRECT && current->next->type == TEXT)
			current->next->type = APP_FILE;
		else if (current->type == TEXT && flag == 1)
		{
			current->type = COMMAND;
			flag = 0;
		}
		else if (current->type == TEXT)
			current->type = STRING;
		current = current->next;
	}
	return ;
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
