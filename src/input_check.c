/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 14:59:26 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 13:51:32 by lade-kon      ########   odam.nl         */
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

// In this function I check if there comes a file after a redirect. If there is no node
// after the redirect the functions returns false. The function also returns false if
// if there is another redirect following. 
int		input_check(t_data *data)
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
				return (-2);//should be Syntax Error
			else if (is_redirect(next) == true)
				return (-2);//should be Syntax Error
		}
		current = next;
	}
	return (0);
}
