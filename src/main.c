/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/04 12:21:54 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_data	*data;
	int		x;

	(void)argv;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	data = init_struct(env);
	if (data == NULL)
		ft_error(NULL, -1);
	while (1)
	{
		input = readline("Crab-shell$ ");
		if (!input)
			break;
		if (*input && input[0] != '\0')
			add_history(input);
		data->input = ft_substr(input, 0, ft_strlen(input));
		free(input);
		x = ft_lexer(data, data->input);
		ft_error(data, x);
		x = get_procs(data);
		ft_error(data, x);
		//before stuff goes in the executor the quotes have to be deleted.
		//and the last input check has to be performed.
		x = executor(data);
		if (x)
			printf("exit_code = %d\n", x);
		free_struct(data);
	}
	return (0);
}
