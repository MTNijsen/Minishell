/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:35:25 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 13:59:58 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	realloc_envp(t_data *data, size_t size)
{
	size_t	i;
	char	**output;

	i = 0;
	output = (char **)malloc(sizeof(char *) * size);
	if (output == NULL)
		clean_exit(data, MALLOC_ERROR);
	while (data->envp && data->envp[i])
	{
		output[i] = ft_strdup(data->envp[i]);
		if (output == NULL)
		{
			ft_free_arr(output);
			clean_exit(data, MALLOC_ERROR);
		}
		i++;
	}
	while (i < size)
	{
		output[i] = NULL;
		i++;
	}
	ft_free_arr(data->envp);
	data->envp = output;
}
