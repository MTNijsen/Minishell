/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 14:49:23 by lde-koni      #+#    #+#                 */
/*   Updated: 2024/10/02 20:27:03 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
