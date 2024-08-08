/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 16:14:45 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*input;
	t_token		*head_tokens;
	t_proc		*head_procs;

	(void)argv;
	(void)env;
	head_tokens = NULL;
	head_procs = NULL;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	while (1)
	{
		input = readline("Crab-shell$ ");
		if (!input)
			break;
		if (*input && input[0] != '\0')
			add_history(input);
		if (!ft_lexer(&head_tokens, input))
			ft_puterror_fd("Error: there was a malloc error.", STDERR_FILENO);
		free(input);
		if (!parse_input(&head_procs, &head_tokens));
			ft_puterror_fd("Something went wrong in parsing.", STDERR_FILENO);
	}
	return (0);
}
