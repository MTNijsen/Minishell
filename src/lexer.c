/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/31 19:48:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	To be able to increment the index in other functions 
	I'm sending a pointer to i in the functions: i++;
*/

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
	
	while (input[i] && end_quote == false)
	{
		i++;
		if (input[i] == quote)
			end_quote = true;
	}
	if (end_quote == false)
		return (-1);
	return (i);
}

int	create_word_token(t_token **head, char *input, int i)
{
	t_token	*token;
	char	*value;
	int		start;
	int		x;

	printf("Creating word token from index [%d]\n", i);
	start = i;
	value = NULL;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			x = handle_quotes(input, i);
			printf("start [%d]\nx [%d]\nchar [%c]\nlen [%d]\n", start, x, input[x], (x - start + 1));
			value = ft_substr(input, (start), (x - start + 1));
			i = x;
			break;
		}
		else
		{
			while (input[i] && !ft_isspecial(input[i], " |<>\"\'"))
				i++;
			value = ft_substr(input, start, (i - start));
			break;
		}
	}
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(head, token);
	return (i + 1);
}

int	create_redir_token(t_token **head, char *input, int i)
{
	t_token	*token;

	printf("Creating redirect token from index [%d]\n", i);
	token = NULL;
	if (input[i] == '<' && input[++i])
	{
		if (input[i] == '<')
		{
			token = create_token(HEREDOC, "<<\0");
			i++;
		}
		else
			token = create_token(IN_REDIRECT, "<\0");
	}
	if (input[i] == '>' && input[++i])
	{
		if (input[i] == '>')
		{
			token = create_token(APP_REDIRECT, ">>\0");
			i++;
		}
		else
			token = create_token(OUT_REDIRECT, ">\0");
	}
	if (token == NULL)
		return (-1);
	add_token(head, token);
	return (i);
}

int	create_pipe_token(t_token **head, int i)
{
	t_token	*token;

	printf("Creating pipe token from index [%d]\n", i);
	token = create_token(PIPE, "|\0");
	if (token == NULL)
		return (-1);
	add_token(head, token);
	i++;
	return (i);
}

bool	ft_lexer(t_token **head, char *input)
{
	int	i;
	int	x;

	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			i++;
		else if (input[i] == '|')
			x = create_pipe_token(head, i);
		else if (input[i] == '<' || input[i] == '<')
			x = create_redir_token(head, input, i);
		else
			x = create_word_token(head, input, i);
		printf("x = [%d]\n", x);
		if (x < 0)
			return (false);
		i = x;
	}
	return (true);
}
