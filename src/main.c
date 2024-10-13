/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/13 16:43:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int	g_sign = 0;

static void	get_line(t_data *data)
{
	char	*input;

	input = readline("Crab-shell$ ");
	if (!input)
	{
		write(2, "exit\n", 5);
		clean_exit(data, data->exit_code);
	}
	if (g_sign == SIGINT)
	{
		g_sign = 0;
		data->exit_code = 130;
	}
	if (input[0] != '\0')
		add_history(input);
	data->input = ft_strdup(input);
	free(input);
}

static int	parse(t_data *data)
{
	int	x;

	x = ft_lexer(data, data->input);
	if (x != 0)
		return (ft_error(data, x));
	env_expand(data);
	x = handle_quotes(data);
	if (x != 0)
		return (ft_error(data, x));
	x = get_procs(data);
	if (x != 0)
		return (ft_error(data, x));
	return (x);
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
		get_line(&data);
		x = parse(&data);
		if (x == SUCCESS)
			x = executor(&data);
		if (x)
			printf("exit_code = %d\n", x);
		clean_data(&data);
		data.exit_code = x;
	}
	free_data(&data);
	return (0);
}
