/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 15:27:07 by mnijsen       #+#    #+#                 */
/*   Updated: 2023/11/20 15:18:15 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long long	tot_size;
	void				*alloc;

	if (nmemb == 0 || size == 0)
		return (NULL);
	else
		tot_size = nmemb * size;
	if (tot_size / size == nmemb)
	{
		alloc = malloc(tot_size);
		if (!alloc)
			return (NULL);
		ft_bzero(alloc, tot_size);
		return (alloc);
	}
	else
		return (NULL);
}
