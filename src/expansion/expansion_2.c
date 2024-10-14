/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion_2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/13 14:23:27 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 14:17:51 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	len_till_quote(char *text)
{
	int	i;

	i = 0;
	if (ft_isdigit(text[i]))
		return (0);
	while (text[i] != '\0' && text[i] != '=')
	{
		if (!ft_isalnum(text[i]) && text[i] != '_')
			return (i);
		i++;
	}
	return (i);
}

char	*fix_spaces(t_token **cur_token, char *current, int i)
{
	t_token	*next_token;
	char	*temp;

	temp = ft_substr(current, 0, i);
	if (temp == NULL)
		return (NULL);
	while (current[i] == ' ')
		i++;
	(*cur_token)->value = temp;
	temp = ft_substr(current, i, ft_strlen(current) - i);
	if (temp == NULL)
		return (NULL);
	next_token = create_token(TEXT, temp);
	if (next_token == NULL)
		return (NULL);
	next_token->next = (*cur_token)->next;
	(*cur_token)->next = next_token;
	(*cur_token) = (*cur_token)->next;
	return (temp);
}

static char	*expand_exit(char *front_string, char *end_string, \
	int exit_code, int *i)
{
	char	*new_text;
	char	*env_val;

	env_val = ft_itoa(exit_code);
	if (env_val == NULL)
		return (free(front_string), free(end_string), NULL);
	new_text = ft_triappend(front_string, env_val, end_string);
	*i += ft_strlen(env_val) -2;
	free(env_val);
	free(front_string);
	free(end_string);
	return (new_text);
}

static int	get_front_and_back(char **front_string, \
	char **end_string, char *text, int i)
{
	*front_string = ft_substr(text, 0, i -1);
	if (*front_string == NULL)
		return (-1);
	*end_string = ft_substr(text, i + len_till_quote(&text[i]), \
		ft_strlen(text + i + len_till_quote(&text[i])));
	if (*end_string == NULL)
		return (free(*front_string), -1);
	return (0);
}

char	*expand_env(char **envp, char *text, int *i, int exit_code)
{
	char	*new_text;
	char	*env_var;
	char	*front_string;
	char	*end_string;
	char	*env_val;

	if (get_front_and_back(&front_string, &end_string, text, *i))
		return (NULL);
	if (text[*i] == '?')
		return (expand_exit(front_string, end_string, exit_code, i));
	env_var = ft_substr(text, *i, len_till_quote(&text[*i]));
	if (env_var == NULL)
		return (free(front_string), free(end_string), NULL);
	env_val = return_env_val(envp, env_var);
	if (env_val == NULL)
		env_val = "";
	new_text = ft_triappend(front_string, env_val, end_string);
	*i += ft_strlen(env_val) - 2;
	return (free(env_var), free(front_string), free(end_string), new_text);
}
