/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_proc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:16:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 16:18:44 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_proc(t_proc **head, t_proc *new)
{
	t_proc	*last_node;

	if (*head == NULL)
		*head = new;
	else
	{
		last_node = last_token(*head);
		last_node->next = new;
	}
}
