/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_procs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 18:39:39 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_procs(t_proc *lst)
{
	int	x;

	x = 0;
	while (lst != NULL)
	{
		printf("--------\n");
		printf("|PROC %i|\n", lst->index);
		printf("--------\n");
		printf("TOKENS: [%d]\n", lst->token_count);
		printf("CMD: [%s]\n", lst->cmd);
		while (lst->argv[x])
		{
			printf("ARGV[%i]: [%s]\n", x, lst->argv[x]);
			x++;
		}
		while (lst->redirs != NULL)
		{
			printf("TYPE: [%d]	VALUE: [%s]\n", lst->redirs->type, lst->redirs->file);
			lst->redirs = lst->redirs->next;
		}
		lst = lst->next;
	}
}
