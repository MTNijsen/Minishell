/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:35:17 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:19:18 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
	{
		i++;
	}
	while (i < size && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j != 0 && i == size)
		dst[i - 1] = '\0';
	else if (j != 0)
		dst[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}
