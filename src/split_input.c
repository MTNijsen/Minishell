/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:04:07 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 13:41:41 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**split_input(t_output data, char *input, char c)
{
	char	**arr;
	size_t	words;
	char	*str;

	str = input;
	if (!input)
		return (NULL);
	words = word_count((char *)input, c);
	arr = ft_calloc(words + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = fill_arr(arr, str, c, words);
	return (arr);
}
