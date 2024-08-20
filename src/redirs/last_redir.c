/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   last_redir.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/15 14:26:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:27:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*last_redir(t_redir *lst)
{
	t_redir	*current_node;

	current_node = lst;
	if (current_node == NULL)
		return (NULL);
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}
