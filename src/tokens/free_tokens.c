/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 09:05:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:07:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_data *data)
{
	t_token	*current;
	t_token	*next;

	current = data->tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	data->tokens = NULL;
}
