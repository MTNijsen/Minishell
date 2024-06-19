/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:14:59 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:54 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			minus_count;
	long long	nbr;

	i = 0;
	minus_count = 1;
	nbr = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus_count *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += nptr[i] - 48;
		i++;
	}
	return (nbr * minus_count);
}
