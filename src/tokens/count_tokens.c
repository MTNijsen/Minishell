/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 18:02:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 18:44:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_tokens(t_token **tokens)
{
	t_token	*current;
	int		count;

	count = 0;
	current = *tokens;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
