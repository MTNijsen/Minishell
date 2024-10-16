/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 12:31:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 18:00:50 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_env(char **envp, char *text, int *i, int exit_code);
void	fix_spaces(t_token **cur_token, char *current, int i);

static void	expand_token(t_data *data, t_token *current)
{
	int		i;
	char	*text;
	char	*temp;

	i = -1;
	text = current->value;
	while (i++ < (int)ft_strlen(text))
	{
		if (text[i] == '$' && text[i + 1] != '\0')
		{
			i++;
			temp = expand_env(data->envp, text, &i, data->exit_code);
			free(text);
			if (temp == NULL)
				clean_exit(data, MALLOC_ERROR);
			text = temp;
		}
		else if (text[i] == '\'')
		{
			i++;
			while (text[i] != '\'' && text[i] != '\0')
				i++;
		}
	}
	current->value = text;
}

static int	token_split(t_token **cur_token)
{
	char	type;
	int		i;

	i = 0;
	type = '\0';
	while ((*cur_token)->value[i])
	{
		if (((*cur_token)->value[i] == '\'' || \
			(*cur_token)->value[i] == '\"') && type == '\0')
			type = (*cur_token)->value[i];
		else if ((*cur_token)->value[i] == type && type != '\0')
			type = '\0';
		else if ((*cur_token)->value[i] == ' ' && type == '\0')
		{
			fix_spaces(cur_token, (*cur_token)->value, i);
			i = -1;
		}
		i++;
	}
	return (0);
}

static int	expand_home(t_data *data, t_token *current)
{
	free(current->value);
	current->value = return_env_val(data->envp, "HOME");
	if (current->value == NULL)
	{
		write(2, "Error: HOME not set\n", 21);
		return (COMMON_ERROR);
	}
	current->value = ft_strdup(current->value);
	if (current->value == NULL)
		clean_exit(data, MALLOC_ERROR);
	return (0);
}

int	env_expand(t_data *data)
{
	t_token	*current;
	int		x;

	current = data->tokens;
	while (current != NULL)
	{
		if (!ft_strncmp(current->value, "~", 2))
		{
			x = 0;
			x = expand_home(data, current);
			if (x != 0)
				return (x);
		}
		else
		{
			expand_token(data, current);
			if (token_split(&current) == -1)
				clean_exit(data, MALLOC_ERROR);
		}
		current = current->next;
	}
	return (0);
}
