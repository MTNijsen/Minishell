/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_quotes.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/16 13:43:12 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_str(t_data *data, t_token *token)
{
	char	*str;

	str = ft_strdup(token->value);
	if (!str)
		clean_exit(data, MALLOC_ERROR);
	free(token->value);
	token->value = NULL;
	token->value = remove_quotes(str);
	if (token->value == NULL)
	{
		free(str);
		return (SYNTAX_ERROR);
	}
	free(str);
	return (SUCCESS);
}

int	handle_cmd(t_data *data, t_token *token)
{
	char	*str;

	str = ft_strdup(token->value);
	if (!str)
		clean_exit(data, MALLOC_ERROR);
	free(token->value);
	token->value = NULL;
	token->value = remove_quotes(str);
	if (check_spaces(str) || token->value == NULL)
	{
		free(str);
		return (SYNTAX_ERROR);
	}
	free(str);
	return (SUCCESS);
}

int	str_or_cmd(t_data *data, t_token *token)
{
	int	x;

	x = 0;
	if (token->type == COMMAND)
		x = handle_cmd(data, token);
	else if (token->type == STRING)
		x = handle_str(data, token);
	else
		return (SUCCESS);
	return (x);
}

/**
 * @brief	if the cmd has quotes, there has to be a check if there are
 * 			spaces, if so cmd is invalid
 */
int	handle_quotes(t_data *data)
{
	t_token	*token;
	int		x;

	x = 0;
	token = data->tokens;
	while (token != NULL)
	{
		printf("token value: %s\n", token->value);
		if (token->value && check_quotes(token->value))
			x = str_or_cmd(data, token);
		if (x == SYNTAX_ERROR)
			return (SYNTAX_ERROR);
		token = token->next;
	}
	return (SUCCESS);
}
