/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_arr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/07 17:48:31 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/07 17:49:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_arr(char **arr)
{
	int	x;

	x = 0;
	while (arr[x])
	{
		printf("arr[%i] = %s\n", x, arr[x]);
		x++;
	}
}
