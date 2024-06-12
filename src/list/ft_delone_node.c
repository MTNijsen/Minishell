/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delone_node.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 16:14:55 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 12:40:49 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.

lst: The node to free.
del: The address of the function used to delete the content.*/

#include "minishell.h"

void	ft_lstdelone(t_output *lst, void (*del)(void*))
{
	(*del)(lst->content);
	free (lst);
}
