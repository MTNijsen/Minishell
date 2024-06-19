/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 11:43:16 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:21 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *sorc, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	if (!dest && !sorc)
		return (dest);
	i = 0;
	dst = (char *)dest;
	src = (const char *)sorc;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dest);
}
