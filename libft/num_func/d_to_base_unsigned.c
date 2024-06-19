/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_to_base_unsigned.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 12:49:13 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:46 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	udigit_count(size_t input, int base)
{
	int	digits;

	digits = 0;
	if (input == 0)
		digits++;
	while (input > 0)
	{
		digits++;
		input /= base;
	}
	return (digits);
}

char	*ud_to_base(size_t input, char *base_chars)
{
	int const	base = ft_strlen(base_chars);
	int const	digits = udigit_count(input, base);
	char		*output;
	int			i;

	output = (char *)ft_calloc((digits + 1), sizeof(char));
	if (!output)
		return (NULL);
	i = 1;
	if (input == 0)
		output[0] = '0';
	while (input > 0)
	{
		output[digits - i++] = base_chars[input % base];
		input /= base;
	}
	return (output);
}
