/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_unset.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:18 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/04 19:28:02 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
