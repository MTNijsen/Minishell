/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 14:59:26 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 16:33:31 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// In this function I check from text after a redirect. If there is no node
// after the redirect the functions returns false. 
bool	input_check(t_token **token_lst)
{
	t_token	*current;
	t_token	*next;

	current = *token_lst;
	next = NULL;
	while (current)
	{
		next = current->next;
		if (current->type != PIPE && current->type != STRING)
		{
			if (next == NULL || next->type != STRING)
				return (false);
		}
		current = next;
	}
	return (true);
}
