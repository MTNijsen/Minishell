/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 21:18:48 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/02 15:40:53 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_special(char input, const char *check)
{
	int	i;

	i = 0;
	while (check[i])
	{
		if (input == check[i])
			return (true);
		i++;
	}
	return (false);
}

