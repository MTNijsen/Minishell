/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_node_front.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 22:03:05 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 19:15:10 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*Adds the node ’new’ at the beginning of the list.
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.*/

#include "minishell.h"

void	ft_add_node_front(t_output **lst, t_output *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
