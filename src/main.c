/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/13 14:16:41 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_stdin_input(int fd)
{
	char	*line;
	char	**input;

	line = get_next_line(fd);
	while (line)
	{
		input = ft_split(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (input);
}

int	main(int argc, char **argv)
{
	char	**input;

	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	while (1)
	{
		input = get_stdin_input(STDIN_FILENO);
		parse(input);
	}
	return (0);
}