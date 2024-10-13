/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 12:31:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/13 14:50:44 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env(char **envp, char *text, int *i, int exit_code);
char	*fix_spaces(t_token **cur_token, char *current, int i);

static void	expand_token(t_data *data, t_token *current)
{
	int		i;
	char	*text;

	i = -1;
	text = current->value;
	while (i++ < (int)ft_strlen(text))
	{
		if (text[i] == '$')
		{
			i++;
			text = expand_env(data->envp, text, &i, data->exit_code);
			if (text == NULL)
				clean_exit(data, MALLOC_ERROR);
		}
		else if (text[i] == '\'')
		{
			i++;
			while (text[i] != '\'' && text[i] != '\0')
				i++;
		}
	}
	if (current->value != text)
		free(current->value);
	current->value = text;
}

static int	token_split(t_token **cur_token)
{
	char	*current;
	char	*temp;
	char	type;
	int		i;

	i = 0;
	type = '\0';
	current = (*cur_token)->value;
	while (current[i])
	{
		if ((current[i] == '\'' || current[i] == '\"') && type != '\0')
			type = current[i];
		else if (current[i] == type && type != '\0')
			type = '\0';
		else if (current[i] == ' ' && type == '\0')
		{
			temp = fix_spaces(cur_token, current, i);
			free(current);
			current = temp;
			i = -1;
		}
		i++;
	}
	return (0);
}

void	env_expand(t_data *data)
{
	t_token	*current;

	current = data->tokens;
	while (current != NULL)
	{
		expand_token(data, current);
		if (token_split(&current) == -1)
			clean_exit(data, MALLOC_ERROR);
		current = current->next;
	}
}
