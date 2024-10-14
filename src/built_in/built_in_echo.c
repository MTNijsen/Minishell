/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_echo.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:33 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 16:29:08 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	bi_echo(char **argv)
{
	int		flags;
	int		i;

	i = 1;
	flags = 0;
	while (argv[i] != NULL && is_flag(argv[i]))
	{
		flags = 1;
		i++;
	}
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
			i++;
		else
		{
			write(1, argv[i], ft_strlen(argv[i]));
			i++;
			if (argv[i] != NULL)
				write(1, " ", 1);
		}
	}
	if (!flags)
		write(1, "\n", 1);
}
