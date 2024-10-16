/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   modify_env_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:37:49 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 17:53:29 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	find_env(t_data *data, char *env_var)
{
	size_t	var_len;
	char	*temp;
	int		i;

	i = 0;
	temp = strchr(env_var, '=');
	if (temp == NULL)
		var_len = ft_strlen(env_var);
	else
		var_len = temp - env_var;
	while (data->envp[i] != NULL && \
		ft_strncmp(data->envp[i], env_var, var_len + 1) != '\0' && \
		ft_strncmp(data->envp[i], env_var, var_len + 1) != - '=' && \
		ft_strncmp(data->envp[i], env_var, var_len + 1) != '=')
		i++;
	return (i);
}

int	modify_env_var(t_data *data, char *env_var)
{
	int				i;

	i = 0;
	if (!is_valid_env(env_var))
		return (1);
	if (data->envp != NULL)
	{
		i = find_env(data, env_var);
		if (data->envp[i] != NULL)
		{
			free(data->envp[i]);
			data->envp[i] = env_var;
			return (0);
		}
		realloc_envp(data, i +2);
	}
	else
		data->envp = (char **)ft_calloc(2, sizeof(char *));
	if (data->envp == NULL)
		clean_exit(data, MALLOC_ERROR);
	data->envp[i] = env_var;
	return (0);
}
