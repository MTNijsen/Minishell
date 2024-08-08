/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_procs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 09:05:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 16:37:48 by lade-kon      ########   odam.nl         */
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
		if (current->args)
			current->args = ft_free_arr(current->args);
		// free(current);
		current = next;
	}
}
