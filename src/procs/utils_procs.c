/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_procs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/15 15:56:16 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 15:57:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_arguments(t_token *token)
{
	t_token	*current;
	int		argc;

	current = token;
	argc = 0;
	while (current && current->type != PIPE)
	{
		if (current->type == STRING)
			argc++;
		current = current->next;
	}
	return (argc);
}
