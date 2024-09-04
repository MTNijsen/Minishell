/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_token.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 14:16:41 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 20:31:57 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_data *data, t_token *new)
{
	t_token	*last_node;

	if (data->tokens == NULL)
		data->tokens = new;
	else
	{
		last_node = last_token(data->tokens);
		last_node->next = new;
	}
}
