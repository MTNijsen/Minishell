/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_redir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/15 14:23:47 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/21 22:09:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_redir(t_data *data, t_redir *new)
{
	t_redir	*last_node;
	t_redir	**head;

	head = &data->procs->redirs;
	if (*head == NULL)
		*head = new;
	else
	{
		last_node = last_redir(*head);
		last_node->next = new;
	}
}
