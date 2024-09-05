/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   special_tokens.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:21:54 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 17:43:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_left_redir(t_data *data, char *input, int i)
{
	t_token	*token;

	token = NULL;
	if (input[++i] && input[i] == '<')
	{
		token = create_token(HEREDOC, "<<\0");
		i++;
	}
	else
		token = create_token(IN_REDIRECT, "<\0");
	if (token == NULL)
		return (-1);
	add_token(data, token);
	return (i);
}

int	create_right_redir(t_data *data, char *input, int i)
{
	t_token	*token;

	token = NULL;
	if (input[++i] && input[i] == '>')
	{
		token = create_token(APP_REDIRECT, ">>\0");
		i++;
	}
	else
		token = create_token(OUT_REDIRECT, ">\0");
	if (token == NULL)
		return (-1);
	add_token(data, token);
	return (i);
}

int	create_redir_token(t_data *data, char *input, int i)
{
	if (input[i] == '<')
		i = create_left_redir(data, input, i);
	if (input[i] == '>')
		i = create_right_redir(data, input, i);
	return (i);
}

int	create_pipe_token(t_data *data, int i)
{
	t_token	*token;

	token = create_token(PIPE, "|\0");
	if (token == NULL)
		return (-1);
	add_token(data, token);
		// printf("%p\n", data->tokens);

	i++;
	return (i);
}
