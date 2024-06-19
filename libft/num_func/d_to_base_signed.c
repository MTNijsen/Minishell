/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_to_base_signed.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/11 12:49:04 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:33 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	digit_count(ssize_t input, int base)
{
	int	digits;

	digits = 0;
	if (input <= 0)
	{
		digits++;
		input *= -1;
	}
	while (input > 0)
	{
		digits++;
		input /= base;
	}
	return (digits);
}

char	*d_to_base(ssize_t input, char *base_chars)
{
	int const	base = ft_strlen(base_chars);
	int const	digits = digit_count(input, base);
	char		*output;
	int			i;

	output = (char *)ft_calloc((digits + 1), sizeof(char));
	if (!output)
		return (NULL);
	i = 1;
	if (input < 0)
	{
		input *= -1;
		output[0] = '-';
	}
	if (input == 0)
		output[0] = '0';
	while (input > 0)
	{
		output[digits - i++] = base_chars[input % base];
		input /= base;
	}
	output[digits] = '\0';
	return (output);
}
