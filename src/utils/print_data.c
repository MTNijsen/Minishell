/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 15:48:30 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_array(char **arr)
{
	int	x;

	x = 1;
	while (arr[x])
	{
		printf("ARGV[%i]: [%s]\n", x, arr[x]);
		x++;
	}
}

void	print_tokens(t_token *token)
{
	while (token)
	{
		printf("TYPE: [%d]	VALUE: [%s]\n", token->type, token->value);
		token = token->next;
	}
}

void	print_procs(t_proc *proc)
{
	int	i;

	i = 0;
	while (proc)
	{
		printf("--------\n");
		printf("|PROC %i|\n", i);
		printf("--------\n");
		printf("CMD: [%s]\n", proc->argv[0]);
		if (proc->argv)
			print_array(proc->argv);
		if (proc->redirs)
			print_tokens(proc->redirs);
		proc = proc->next;
		i++;
	}
}
