/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_proc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 16:25:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 18:55:19 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_proc	*init_proc(void)
{
	t_proc	*proc;

	proc = (t_proc *)malloc(sizeof(t_proc));
	if (!proc)
		return (NULL);
	proc->cmd = NULL;
	proc->argv = NULL;
	proc->redir = NULL;
	proc->token_count = 0;
	proc->proc_count = 0;
	proc->index = 0;
	proc->next = NULL;

	return (proc);
}