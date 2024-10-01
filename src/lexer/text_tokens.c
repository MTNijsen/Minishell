/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:27:34 by lade-kon      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2024/10/01 16:04:07 by lade-kon      ########   odam.nl         */
=======
/*   Updated: 2024/09/18 16:54:13 by lade-kon      ########   odam.nl         */
>>>>>>> ba12efcfd7d328d4a0ff1965e7858ea4537478d4
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
	while (input[i] && !is_special(input[i], " |<>\"\'"))
		i++;
	value = ft_substr(input, start, (i - start));
	token = create_token(TEXT, value);
	if (token == NULL || value == NULL)
		return (-1);
	add_token(data, token);
	free (value);
	return (i);
}
