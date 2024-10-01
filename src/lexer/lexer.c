/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/01 16:04:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reclassify_text_token(t_data *data, int flag)
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

int	ft_lexer(t_data *data, char *input)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (input[i])
	{
		// printf("ft_lexer data_token: %p\n", data->tokens);
		if (input[i] == ' ')
			x = i + 1;
		else if (input[i] == '|')
			x = create_pipe_token(data, i);
		else if (input[i] == '<' || input[i] == '>')
			x = create_redir_token(data, input, i);
		else
			x = create_text_tokens(data, input, i);
		if (x < 0)
			return (-1);
		i = x;
	}
	reclassify_text_token(data, 1);

	return (input_check(data));
}
