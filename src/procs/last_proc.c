/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_proc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 16:17:34 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 18:57:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_proc	*last_proc(t_proc *lst)
{
	t_proc	*current_node;

	current_node = lst;
	if (current_node == NULL)
		return (NULL);
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}
