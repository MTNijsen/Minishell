/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_list.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 18:35:36 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstprint(t_output *lst)
{
	while (lst != NULL)
	{
		ft_printf("%d ", lst->node);
		lst = lst->next;
	}
	ft_printf("\n");
}
