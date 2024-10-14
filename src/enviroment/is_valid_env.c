/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_valid_env.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:35:02 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 16:15:25 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_valid_env(char *env_var)
{
	int	i;

	i = 0;
	if (env_var == NULL || env_var[0] == '\0')
		return (false);
	if (ft_isdigit(env_var[i]))
		return (false);
	while (env_var[i] != '\0' && env_var[i] != '=')
	{
		if (!ft_isalnum(env_var[i]) && env_var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
