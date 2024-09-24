/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   realloc_env.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:35:25 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 13:56:55 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**realloc_envp(char **envp, size_t size, size_t *old_size)
{
	size_t	i;
	char	**output;

	i = 0;
	output = (char **)malloc(sizeof(char *) * size);
	if (output == NULL)
		return (NULL);
	while (i < size && i < *old_size)
	{
		output[i] = ft_strdup(envp[i]);
		if (output == NULL)
			return (ft_free_arr(output), NULL);
		i++;
	}
	while (i < size)
	{
		output[i] = NULL;
		i++;
	}
	*old_size = size;
	ft_free_arr(envp);
	return (output);
}
