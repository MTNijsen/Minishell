/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   modify_env_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:37:49 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 13:54:26 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	modify_env_var(t_data *data, char *env_var)
{
	int				i;
	const size_t	var_len = strchr(env_var, '=') - env_var;

	i = 0;
	if (!is_valid_env(env_var))
		return (1);
	if (data->envp != NULL)
	{
		while (data->envp[i] != NULL && \
			ft_strncmp(data->envp[i], env_var, var_len +1))
			i++;
		if (data->envp[i] != NULL)
		{
			free(data->envp[i]);
			data->envp[i] = env_var;
			return (0);
		}
		data->envp = realloc_envp(data->envp, i +2, i +1);
	}
	else
		data->envp = (char **)ft_calloc(2, sizeof(char *));
	if (data->envp == NULL)
		clean_exit(data, MALLOC_ERROR);
	data->envp[i] = env_var;
	return (0);
}
