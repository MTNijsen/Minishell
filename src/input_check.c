/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 14:59:26 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/10 21:25:17 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redirect(t_token *token)
{
	if (token->type == IN_REDIRECT)
		return (true);
	else if (token->type == OUT_REDIRECT)
		return (true);
	else if (token->type == APP_REDIRECT)
		return (true);
	else if (token->type == HEREDOC)
		return (true);
	return (false);
}

/**
 * @brief	The function returns an error if:
 * 			- There is no file after the redirect.
 * 			- There is nothing after the redirect.
 * 			- There is another redirect after the redirect.
 * 			- There is nothing after the pipe. 
 */
int	input_check(t_data *data)
{
	t_token	*current;
	t_token	*next;

	current = data->tokens;
	next = NULL;
	while (current)
	{
		next = current->next;
		if (is_redirect(current) == true)
		{
			if (next == NULL || next->type != FILES)
				return (SYNTAX_ERROR);
			else if (is_redirect(next) == true)
				return (SYNTAX_ERROR);
		}
		else if (current->type == PIPE && current->next == NULL)
			return (SYNTAX_ERROR);
		current = next;
	}
	return (0);
}
