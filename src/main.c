/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/31 19:23:04 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char		*input;
	t_token		*head;

	(void)argv;
	head = NULL;
	if (argc != 1)
		ft_puterror_fd("That's too many arguments bro!", STDERR_FILENO);
	// input = readline("Crab-shell$ ");
	while (1)
	{
		input = readline("Crab-shell$ ");
		if (!input)
			break;
		if (*input)
			add_history(input);
		if (ft_lexer(&head, input))
		{
			print_tokens(head);
			free_tokens(&head);
			head = NULL;
		}
			printf("Lexing completed\n");
		free(input);
	}
	return (0);
}
