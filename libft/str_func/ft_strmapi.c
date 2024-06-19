/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:58:46 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:19:24 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			s_len;
	char			*f_s;
	unsigned int	i;

	i = 0;
	s_len = ft_strlen(s);
	f_s = ft_strdup(s);
	if (!f_s)
		return (NULL);
	while (i < s_len)
	{
		f_s[i] = (*f)(i, f_s[i]);
		i++;
	}
	return (f_s);
}
