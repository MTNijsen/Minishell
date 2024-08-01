/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 14:59:26 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/01 22:06:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	input_check(t_token **token_lst)
{
	t_token	*current;
	t_token	*next;

	current = *token_lst;
	next = NULL;
	while (current)
	{
		next = current->next;
		if (current->type != PIPE && current->type != TEXT)
		{
			if (next == NULL || next->type != TEXT)
				return (false);
		}
		current = next;
	}
	return (true);
}
