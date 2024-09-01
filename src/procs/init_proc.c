/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_proc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 16:25:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/29 17:43:39 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_proc	*init_proc(t_token *current)
{
	t_proc	*proc;

	proc = (t_proc *)malloc(sizeof(t_proc));
	if (!proc)
		return (NULL);
	ft_bzero(proc, sizeof(t_proc));
	proc->token_count = count_tokens_proc(current); //possibly not needed, maybe remove at end
	proc->next = NULL;
	// proc->cmd = NULL;
	// proc->argv = NULL;
	// proc->redirs = NULL;
	// proc->token_count = 0;
	// proc->index = 0;
	return (proc);
}
