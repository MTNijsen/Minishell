/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_procs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 09:05:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 19:02:15 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_procs(t_proc **procs)
{
	t_proc	*current;
	t_proc	*next;

	current = *procs;
	while (current)
	{
		next = current->next;
		if (current->cmd)
			free(current->cmd);
		if (current->argv)
			current->argv = ft_free_arr(current->argv);
		if (current->redir)
			current->redir = ft_free_arr(current->redir);
		free(current);
		current = next;
	}
}
