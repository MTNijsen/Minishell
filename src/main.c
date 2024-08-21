/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/21 22:03:34 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;
	t_data	*data;
	int		x;

	(void)argv;
	(void)env;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	data = init_struct();
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
		x = ft_lexer(data);
		ft_error(data, x);
		x = get_procs(data);
		print_tokens(data->tokens);
		printf("-----------------------\n");
		print_procs(data->procs);
		free_tokens(data);
	}
	return (0);
}