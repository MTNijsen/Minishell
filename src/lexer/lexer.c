/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/01 21:35:07 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



bool	ft_lexer(t_token **head, char *input)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			x = i + 1;
		else if (input[i] == '|')
			x = create_pipe_token(head, i);
		else if (input[i] == '<' || input[i] == '>')
			x = create_redir_token(head, input, i);
		else
			x = create_text_token(head, input, i);
		if (x < 0)
			return (false);
		i = x;
	}
	return (true);
}
