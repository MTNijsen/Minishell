/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_procs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 19:01:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_procs(t_proc *lst)
{
	int	x;

	x = 0;
	while (lst != NULL)
	{
		printf("CMD: [%s]\n", lst->cmd);
		while (lst->argv[x])
		{
			printf("ARGV[%i]: [%s]\n", x, lst->argv[x]);
			x++;
		}
		
		lst = lst->next;
	}
}
