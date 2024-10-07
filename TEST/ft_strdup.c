/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/17 21:24:24 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/02 20:26:59 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	slen;

	slen = ft_strlen(s1);
	dup = (char *)ft_calloc((slen + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	else
		ft_memcpy(dup, s1, slen);
	return (dup);
}

// #include <string.h>
// int	main()
// {
// 	char	string[] = "";

// 	printf("%s\n", ft_strdup(string));
// 	printf("%s\n", strdup(string));
// }