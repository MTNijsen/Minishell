/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:04:53 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:23 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *sorc, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	if (!dest && !sorc)
		return (dest);
	dst = (char *)dest;
	src = (const char *)sorc;
	if (dst > src)
	{
		i = n +1;
		while (--i > 0)
			dst[i - 1] = src[i - 1];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dest);
}
