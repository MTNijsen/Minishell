/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_env_var.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:38:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 13:55:46 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env_var(t_data *data, char *name)
{
	size_t			i;
	const size_t	name_len = ft_strlen(name);

	i = 0;
	if (data->envp == NULL)
		return ;
	while (data->envp[i] != NULL && \
		ft_strncmp(data->envp[i], name, name_len +1) != '=')
		i++;
	if (data->envp[i] != NULL)
	{
		free(data->envp[i]);
		while (data->envp[i +1] != NULL)
		{
			data->envp[i] = data->envp[i +1];
			i++;
		}
		data->envp[i] = data->envp[i +1];
	}
}
