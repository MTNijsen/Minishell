/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_redirs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:19:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 16:24:31 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirs(t_redir **redirs)
{
	t_redir	*current;
	t_redir	*next;

	current = *redirs;
	while (current)
	{
		next = current->next;
		if (current->file)
			free(current->file);
		free(current);
		current = next;
	}
}
