/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/16 19:09:36 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int g_sign = 0;

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_data	*data;
	int		x;

	(void)argv;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	data = init_struct(env);
	set_sig(S_INTERACTIVE);
	if (data == NULL)
		ft_error(NULL, -1);
	while (1)
	{
		input = readline("Crab-shell$ ");
		if (!input)
			break;
		if (g_sign == SIGINT)
		{
			g_sign = 0;
			x = 130;
		}
		if (*input && input[0] != '\0')
			add_history(input);
		data->input = ft_substr(input, 0, ft_strlen(input));
		free(input);
		x = ft_lexer(data, data->input);
		ft_error(data, x);
		x = get_procs(data);
		ft_error(data, x);
		x = executor(data);
		if (x)
			printf("exit_code = %d\n", x);
		if (g_sign)
			printf("signal received = %d\n", g_sign);
		free_struct(data);
	}
	clean_exit(data, 130);
	return (0);
}
