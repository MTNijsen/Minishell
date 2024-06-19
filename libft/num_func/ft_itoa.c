/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 15:25:22 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:58 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_itoa_assignment(int n, char *n_str, size_t n_size)
{
	int			i;
	long long	n_temp;

	i = n_size - 1;
	n_temp = n;
	if (n_temp < 0)
		n_temp *= -1;
	while (n_temp != 0)
	{
		n_str[i] = n_temp % 10 + '0';
		n_temp /= 10;
		i--;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	size_t	n_size;
	int		n_temp;
	char	*n_str;

	n_size = 0;
	n_temp = n;
	if (n <= 0)
		n_size++;
	while (n_temp != 0)
	{
		n_temp /= 10;
		n_size++;
	}
	n_str = (char *)ft_calloc((n_size + 1), sizeof(char));
	if (!n_str)
		return (NULL);
	ft_bzero(n_str, n_size);
	if (n < 0)
		n_str[0] = '-';
	if (n == 0)
		n_str[0] = '0';
	else
		n_str = ft_itoa_assignment(n, n_str, n_size);
	return (n_str);
}
