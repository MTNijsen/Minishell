/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:16:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:01:43 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_data *data, t_token *new)
{
	t_token	*last_node;
	t_token	**head;

	head = &data->tokens;
	if (*head == NULL)
		*head = new;
	else
	{
		last_node = last_token(*head);
		last_node->next = new;
	}
}
