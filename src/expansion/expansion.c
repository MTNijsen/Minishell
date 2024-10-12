/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/03 12:31:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/12 16:25:46 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int len_till_quote(char *text)
{
	int	i;

	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == '\'' || text[i] == '\"' || text[i] == '$')
			return (i);
		i++;
	}
	return (i);
}


static int	token_split(t_token **cur_token)
{
	char	*current;
	t_token	*next_token;
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
			temp = ft_substr(current, 0, i);
			if (temp == NULL)
				return (-1);//clean_exit
			while (current[i] == ' ')
				i++;
			(*cur_token)->value = temp;
			temp = ft_substr(current, i, ft_strlen(current) - i);
			if (temp == NULL)
				return (-1);//clean_exit
			next_token = create_token(TEXT, temp);
			if (next_token == NULL)
				return (-1);//clean_exit
			next_token->next = (*cur_token)->next;
			(*cur_token)->next = next_token;
			(*cur_token) = (*cur_token)->next;
			free(current);
			current = temp;
			i = -1;
		}
		i++;
	}
	return (0);
}

static char *expand_env(char **envp, char *text, int *i, int exit_code)
{
	char	*new_text;
	char	*env_var;
	char	*front_string;
	char	*end_string;
	char	*env_val;
	
	front_string = ft_substr(text, 0, *i -1);
	if (front_string == NULL)
		return (NULL);//clean_exit
	end_string = ft_substr(text, *i + len_till_quote(&text[*i]), ft_strlen(text + *i + len_till_quote(&text[*i])));
	if (end_string == NULL)
		return (free(front_string), free(end_string), NULL);//clean_exit
	if (text[*i] != '?')
	{
		env_var = ft_substr(text, *i, len_till_quote(&text[*i]));
		if (env_var == NULL)
			return (free(front_string), NULL);//clean_exit
		env_val = return_env_val(envp, env_var);
		if (env_val == NULL)
			env_val = "";
	}
	else
	{
		env_var = NULL;
		env_val = ft_itoa(exit_code);
	}
	new_text = ft_triappend(front_string, env_val, end_string);
	*i += ft_strlen(env_val) -1;
	if (env_var == NULL)
		free(env_val);
	free(env_var);
	free(front_string);
	free(end_string);
	return (new_text);
}

static void	expand_token(t_data *data, t_token *current)
{
	int		i;
	char	*text;

	i = 0;
	text = current->value;
	while (text[i] != '\0')
	{
		if (text[i] == '$')
		{
			i++;
			text = expand_env(data->envp, text, &i, data->exit_code);
		}
		else if (text[i] == '\'')
		{
			i++;
			while (text[i] != '\'' && text[i] != '\0')
				i++;
			if (text[i] == '\0')
				break ;
			i++;
		}
		else
			i++;
	}
	if (current->value != text)
		free(current->value);
	current->value = text;
}

void	env_expand(t_data *data)
{
	t_token *current;

	current = data->tokens;
	while(current != NULL)
	{
		expand_token(data, current);
		token_split(&current);
		current = current->next;
	}
}