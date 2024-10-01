/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expand_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/18 13:39:23 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/18 17:46:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	insert_token(t_token **head, t_token *to_insert)
{
	t_token	*current;
	t_token	*last_new_token;
	
}


int	insert_text_tokens(t_data *data, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	while (input[i] && !is_special(input[i], " "))
		i++;
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	insert_token(data->tokens, token);
	free (value);
	return (i);
}

/**
 * @brief	In this function there will be a second lexing round. It starts after the expansion. 
 * 			Since all the peaces of input have to be used as single tokens. 
 * 
 */
int	ft_lexer_2(t_data *data, char *input)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (input[i])
	{
		if (input[i] == ' ')
			x = i + 1;
		else
			x = insert_text_tokens(data, input, i);
		if (x < 0)
			return (-1);
		i = x;
	return (input_check(data));
	}
}