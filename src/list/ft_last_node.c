/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_last_node.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:12:28 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 12:38:31 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_output	*ft_last_node(t_output *lst)
{
	t_output	*current_node;

	current_node = lst;
	if (current_node == NULL)
		return (NULL);
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}
