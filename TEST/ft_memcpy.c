/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:16:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/02 20:26:51 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*DESCRIPTION
       The  memcpy()  function copies n bytes from memory area src to memory 
	   area dest.  The memory areas must not overlap.  
	   Use memmove(3) if the memory areas do overlap.

RETURN VALUE
       The memcpy() function returns a pointer to dest.*/

#include "test.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst_char;
	const char	*src_char;

	dst_char = (char *)dst;
	src_char = (const char *)src;
	i = 0;
	if (dst != NULL || src != NULL)
	{
		while (i < n)
		{
			dst_char[i] = src_char[i];
			i++;
		}
	}
	return (dst);
}

// int	main()
// {
// 	char src[] = "copy this";
// 	char dest[100] = "destination";

// 	printf("Dest: %s\n", dest);
// 	printf("Copied in dst: %s\n", memcpy(dest, src, strlen(src) +1));

// 	printf("Own memcpy: %s\n", ft_memcpy(dest, src, strlen(src) +1));

// }
