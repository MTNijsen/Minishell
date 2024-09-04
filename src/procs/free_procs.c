/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_procs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 09:05:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 20:51:44 by lade-kon      ########   odam.nl         */
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
			ft_free_arr(&current->argv);
		if (current->redirs)
			free_tokens(&current->redirs);
		free(current);
		current = next;
	}
	procs = NULL;
}
