/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_last_node.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:12:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 19:22:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_last_node(t_token *lst)
{
	t_token	*current_node;

	current_node = lst;
	if (current_node == NULL)
		return (NULL);
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}
