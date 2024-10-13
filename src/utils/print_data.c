/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 11:38:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_procs(t_proc *lst)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (lst)
	{
		printf("--------\n");
		printf("|PROC %i|\n", i);
		printf("--------\n");
		printf("CMD: [%s]\n", lst->argv[0]);
		if (lst->argv)
		{
			while (lst->argv[x])
			{
				printf("ARGV[%i]: [%s]\n", x, lst->argv[x]);
				x++;
			}
		}
		while (lst && lst->redirs)
		{
			printf("TYPE: [%d]	VALUE: [%s]\n", lst->redirs->type, lst->redirs->value);
			lst->redirs = lst->redirs->next;
		}
		lst = lst->next;
		i++;
	}
}
