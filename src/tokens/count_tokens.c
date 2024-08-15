/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 18:02:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:08:00 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_tokens(t_data *data)
{
	t_token	*current;
	int		count;

	count = 0;
	current = data->tokens;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
