/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:04:07 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/13 14:09:12 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_output	make_parse_list(char **input)
{
	t_output	*head;
	char		*data;
	int			i;

	head = NULL;
	i = 0;
	while (input[i])
	{
		data = input[i];
		ft_add_node_back(&head, ft_new_node(data));
		i++;
	}
	return	(head);
}