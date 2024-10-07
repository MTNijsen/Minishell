/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 20:24:10 by lde-koni      #+#    #+#                 */
/*   Updated: 2024/10/02 20:26:45 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*The bzero() function writes n zeroed bytes to the string s. If n is zero, 
bzero() does nothing.*/

#include "test.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
