/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_array.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/04 19:36:48 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/04 19:58:33 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	copy_array(char ***new_array, char **old_array)
{
	int	i;

	i = 0;
	while (old_array[i] != NULL)
		i++;
	(*new_array) = (char **)ft_calloc(i + 2, sizeof(char *));
	if (!*new_array)
		return (1);
	i = 0;
	while (old_array[i] != NULL)
	{
		(*new_array)[i] = ft_strdup(old_array[i]);
		if (!(*new_array)[i])
			return (ft_free_arr(*new_array), 1);
		i++;
	}
	return (0);
}
