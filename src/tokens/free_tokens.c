/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_tokens.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 09:05:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/16 16:51:04 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token **tokens)
{
	t_token	*current;
	t_token	*next;

	current = *tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	*tokens = NULL;
}
