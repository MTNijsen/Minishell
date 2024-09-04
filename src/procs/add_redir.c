/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_redir.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 16:47:44 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 16:50:10 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_redir(t_token **redirs, t_token *new)
{
	t_token	*last_node;

	if (*redirs == NULL)
		*redirs = new;
	else
	{
		last_node = last_token(*redirs);
		last_node->next = new;
	}
}
