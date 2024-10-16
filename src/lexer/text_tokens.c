/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 16:54:41 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	create_text_token(t_data *data, char *input, int i)
{
	t_token	*token;
	int		start;
	char	*value;

	start = i;
	value = NULL;
	if(is_quote(input[i]) == 1)
	{
		while (is_quote(input[i]) == 0)
			i++;
	}
	else if (is_quote(input[i]) == 0)
	{
		while (input[i] && !is_special(input[i], " |<>"))
			i++;
	}
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}
