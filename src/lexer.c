/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/31 13:29:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	To be able to increment the index in other functions 
	I'm sending a pointer to i in the functions: (*i)++;
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

char	*handle_quotes(char *input, int *i)
{
	unsigned int	start;
	char			*value;
	int				end_quote;
	char			quote;

	start = (unsigned int)(*i);
	quote = input[*i];
	end_quote = false;
	while (end_quote == false)
	{
		(*i)++;
		if (input[*i] == quote)
			end_quote = true;
	}
	value = ft_substr(input, start, (((size_t)(*i)) - start));
	return (value);
}

void	create_word_token(t_token **head, char *input, int *i)
{

	t_token	*token;
	char	*value;
	int		start;

	start = (unsigned int)(*i);
	if (input[*i] == '\"' || input[*i] == '\'')
		value = handle_quotes(input, i);
	else
	{
		while (!ft_isspecial(input[*i], "|<>\"\'"))
			(*i)++;
		value = ft_substr(input, (unsigned int)(*i), (((size_t)(*i)) - start));
	}
	token = create_token(TEXT, value);
	add_token(head, token);
	// free (value); //moet dit? of pas aan het einde van het programma?
	// free (token); //moet dit? of pas aan het einde van het programma?
}

void	create_redir_token(t_token **head, char *input, int *i)
{
	t_token	*token;

	token = NULL;
	if (input[*i] == '<')
	{
		(*i)++;
		if (input[*i] == '<')
		{
			token = create_token(HEREDOC, "<<\0");
			(*i)++;
		}
		token = create_token(IN_REDIRECT, "<\0");
	}
	if (input[*i] == '>')
	{
		(*i)++;
		if (input[*i] == '>')
		{
			token = create_token(APP_REDIRECT, ">>\0");
			(*i)++;
		}
		token = create_token(OUT_REDIRECT, ">\0");
	}
	add_token(head, token);
}

void	create_pipe_token(t_token **head, int *i)
{
	t_token	*token;

	token = create_token(PIPE, "|\0");
	add_token(head, token);
	(*i)++;
}

bool	ft_lexer(t_token **head, char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			i++;
		else if (ft_isspecial(input[i], "|<>"))
		{
			if (input[i] == '|')
				create_pipe_token(head, &i);
			else
				create_redir_token(head, input, &i);
		}
		else
			create_word_token(head, input, &i);
	}

	return (true);
}
