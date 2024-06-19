/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:15:55 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:19:02 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_empty(char **array, int i)
{
	while (--i >= 0)
		free(array[i]);
	free(array);
}

static int	ft_splitlogic(char const *s, char c, int counted, char output[])
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (counted == 3 && s[i] != c)
			output[j] = (char)s[i];
		if (counted == 3 && s[i] != c)
			j++;
		else if ((counted == 2 || counted == 3) && s[i] == c)
			return (j);
		if (counted == 4 && s[i] != c)
			return (j);
		if (counted == 1 && ((s[i] == c && s[i +1] != c && s[i +1] != '\0')
				|| (s[i] != c && i == 0)))
			j++;
		if (counted == 2 && s[i] != c)
			j++;
		if (counted == 4 && s[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		total_strings;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	total_strings = ft_splitlogic(s, c, 1, NULL);
	words = (char **)ft_calloc(total_strings + 1, sizeof(char *));
	if (!words)
		return (NULL);
	while (i < total_strings)
	{
		if (s[0] == c)
			s = &s[ft_splitlogic(s, c, 4, NULL)];
		words[i] = (char *)ft_calloc(ft_splitlogic(s, c, 2, NULL)
				+ 1, sizeof(char));
		if (!words[i])
			ft_empty(words, i);
		if (!words[i])
			return (NULL);
		s = &s[ft_splitlogic(s, c, 3, words[i++])];
	}
	words[i] = NULL;
	return (words);
}
