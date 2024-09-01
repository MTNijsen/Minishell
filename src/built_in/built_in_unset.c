/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_unset.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:18 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 16:51:19 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//unsets all token.values found except first which is the command
void	bi_unset(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		remove_env_var(data, argv[i]);
		i++;
	}
}
