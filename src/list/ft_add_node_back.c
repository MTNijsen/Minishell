/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_add_node_back.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:16:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 18:33:50 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_node_back(t_output **lst, t_output *new)
{
	t_output	*last_node;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_last_node(*lst);
		last_node->next = new;
	}
}
