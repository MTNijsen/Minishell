/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_redirs_proc.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/29 17:15:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/29 17:16:00 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_redirs_proc(t_token *token)
{
	t_redir	*current;
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