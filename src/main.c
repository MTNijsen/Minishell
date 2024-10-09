/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/07 17:56:51 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int	g_sign = 0;

static void	get_line(t_data *data, int *x)
{
	char	*input;

	input = readline("Crab-shell$ ");
	if (!input)
	{
		write(2, "exit\n", 5);
		clean_exit(data, *x);
	}
	if (g_sign == SIGINT)
	{
		g_sign = 0;
		*x = 130;
	}
	if (input[0] != '\0')
		add_history(input);
	data->input = ft_substr(input, 0, ft_strlen(input));
	free(input);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		x;

	(void)argv;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	x = 0;
	init_data(&data, envp);
	while (1)
	{
		get_line(&data, &x);
		x = ft_lexer(&data, data.input);
		ft_error(&data, x);
		env_expand(&data, x);
		x = get_procs(&data);
		ft_error(&data, x);
		//before stuff goes in the executor the quotes have to be deleted.
		x = executor(&data);
		ft_error(&data, x);
		clean_data(&data);
	}
	return (0);
}
