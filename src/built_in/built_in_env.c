/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_env.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:30 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 14:24:41 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->envp && data->envp[i] != NULL && ft_strchr(data->envp[i], '='))
		printf("%s\n", data->envp[i++]);
}
