/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/25 12:12:40 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	To be able to increment the index in other functions 
	I'm sending a pointer to i in the functions: (*i)++;
*/

// int	find_last_quote(char *input, int i)
// {
// 	int len;

// 	while (input[i])
// 	{
// 		i++;
// 		if (input[i] == '\"')
// 			return (i);
// 	}
// 	return (0);
// }

// void	handle_quotes(char *input, int *i)
// {
	
// }
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
		else
			token = create_token(IN_REDIRECT, "<\0");
	}
	else if (input[*i] == '>')
	{
		(*i)++;
		if (input[*i] == '>')
		{
			token = create_token(APP_REDIRECT, ">>\0");
			(*i)++;
		}
		else
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

bool	ft_lexer(t_token **head, char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			i++;
		if (ft_isspecial(input[i], "|<>"))
		{
			if (input[i] == '|')
				create_pipe_token(head, &i);
			else
				create_redir_token(head, input, &i);
		}
		
	}

	return (true);
}
