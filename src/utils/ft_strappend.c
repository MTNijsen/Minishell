/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/06 23:17:26 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 15:00:53 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strappend(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1 && s1[i++])
		;
	while (s2 && s2[j++])
		;
	if (i == 0 && j == 0)
		return (NULL);
	str = (char *)ft_calloc(i + j + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	return (str);
}

char	*ft_triappend(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	len += ft_strlen(s3);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	j = 0;
	while (s3 && s3[j])
		str[i++] = s3[j++];
	return (str);
}

