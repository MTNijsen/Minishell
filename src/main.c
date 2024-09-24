/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/24 18:23:18 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int g_sign = 0;

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	int		x;//we can now just store the exit code in *data

	(void)argv;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	init_data(&data, envp);
	while (1)
	{
		input = readline("Crab-shell$ ");//could we not simply readline directly into data->input
		if (!input)
			break;
		if (g_sign == SIGINT)
		{
			g_sign = 0;
			x = 130;
		}
		if (input[0] != '\0')
			add_history(input);
		data.input = ft_substr(input, 0, ft_strlen(input));
		free(input);
		x = ft_lexer(&data, data.input);
		ft_error(&data, x);
		x = get_procs(&data);
		ft_error(&data, x);
		x = executor(&data);
		ft_error(&data, x);
		clean_data(&data);
	}
	clean_exit(&data, x);
	return (0);
}
