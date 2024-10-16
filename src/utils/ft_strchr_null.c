/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr_null.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/13 15:08:32 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 18:08:14 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr_null(const char *str, int c)
{
	char	*output;

	if (!str)
		return (NULL);
	output = ft_strchr(str, c);
	if (output == NULL)
		return ((char *)&str[ft_strlen(str)]);
	return (output);
}
