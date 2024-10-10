/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_proc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 16:25:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 20:31:32 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_proc	*init_proc(void)
{
	t_proc	*proc;

	proc = (t_proc *)malloc(sizeof(t_proc));
	if (!proc)
		return (NULL);
	ft_bzero(proc, sizeof(t_proc));
	proc->next = NULL;
	proc->argv = NULL;
	return (proc);
}
