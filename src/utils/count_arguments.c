/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_arguments.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/15 15:56:16 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 16:03:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_arguments(t_token *token)
{
	t_token	*current;
	int		argc;

	current = token;
	argc = 0;
	while (current)
	{
		if (current->type == STRING)
			argc++;
		current = current->next;
	}
	return (argc);
}
