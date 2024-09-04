/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   funcs_env.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:14 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/04 19:38:17 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*return_env_val(char **envp, char *name)
{
	size_t			i;
	const size_t	name_len = ft_strlen(name);

	if (!is_valid_env(name))
		return (NULL);
	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], name, name_len +1) != '=' )
		i++;
	if (envp[i] != NULL)
		return (&envp[i][name_len +1]);
	return (NULL);
}
