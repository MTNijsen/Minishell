/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_proc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:16:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 16:15:41 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_proc(t_data *data, t_proc *new)
{
	t_proc	*last_node;
	t_proc	**head;

	head = &data->procs;
	if (*head == NULL)
		*head = new;
	else
	{
		last_node = last_proc(*head);
		last_node->next = new;
	}
}
