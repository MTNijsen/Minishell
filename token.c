/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/24 14:18:01 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 14:18:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(t_type type, const char *value)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->value = ft_strdup(value);
	token->type = type;

	return (token);
}

void	free_token(t_token *token)
{
	if (token->value)
		free(token->value);
	free(token);
}
