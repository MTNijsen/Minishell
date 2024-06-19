/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 23:43:04 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/22 18:30:49 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*s2;
	size_t	i;

	s2 = (char *)ft_calloc(len + 1, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
