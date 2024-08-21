/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 13:47:50 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/21 21:51:25 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lexer(t_data *data)
{
	int		i;
	int		x;
	char	*input;

	input = data->input;
	i = 0;
	x = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			x = i + 1;
		else if (input[i] == '|')
			x = create_pipe_token(data, i);
		else if (input[i] == '<' || input[i] == '>')
			x = create_redir_token(data, input, i);
		else
			x = text_tokens(data, input, i);
		if (x < 0)
			return (-1);
		i = x;
	}
	reclassify_text_token(data, 1);
	return (input_check(data));
}
