/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_new_node.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 21:57:39 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 18:35:28 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.*/

#include "minishell.h"

t_output	*ft_newnode(void *content)
{
	t_output	*new_node;

	new_node = (t_output *)malloc(sizeof(t_output));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->node = content;
	return (new_node);
}
