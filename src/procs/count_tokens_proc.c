/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_tokens_proc.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 18:02:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 21:06:38 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_tokens_proc(t_token *token)
{
	t_token	*current;
	int		count;

	count = 0;
	current = token;
	while (current && current->type != PIPE)
	{
		count++;
		current = current->next;
	}
	return (count);
}
