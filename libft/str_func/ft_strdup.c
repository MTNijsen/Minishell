/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 15:19:29 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:19:11 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	s2 = (char *)ft_calloc(i + 1, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	return (s2);
}
