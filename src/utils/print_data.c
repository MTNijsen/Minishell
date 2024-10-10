/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 17:11:52 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 22:10:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arr(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		printf("ARGV[%i] = %s\n", x, arr[x]);
		x++;
	}
}

void	print_tokens(t_token *lst)
{
	while (lst != NULL)
	{
		printf("TYPE: [%d]	VALUE: [%s]\n", lst->type, lst->value);
		lst = lst->next;
	}
}

void	print_procs(t_proc *lst)
{
	t_token	*redir;
	int		i;

	i = 0;
	redir = lst->redirs;
	while (lst)
	{
		printf("PROC %i\n", i);
		printf("CMD: [%s]\n", lst->cmd);
		if (lst->argv)
			print_arr(lst->argv);
		while (lst && redir)
		{
			printf("TYPE: [%d]	VALUE: [%s]\n", redir->type, redir->value);
			redir = redir->next;
		}
		lst = lst->next;
		i++;
	}
}

void	print_data(t_data *data)
{
	printf("POINTER PROCS: %p\n", data->procs);
	printf("POINTER TOKENS: %p\n", data->tokens);
	printf("INPUT: %s\n", data->input);
}
