/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:08:08 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 16:32:59 by lade-kon      ########   odam.nl         */
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
	while (1)
	{
		input = readline("Crab-shell$ ");
		if (!input)
			break;
		if (*input && input[0] != '\0')
			add_history(input);
		if (ft_lexer(&head, input))
		{
			print_tokens(head);
			if (!input_check(&head))
			{
				printf("Syntax error!!!\n");
				return (-1);
			}
			free_tokens(&head);
			head = NULL;
		}
		else
		{
			printf("Something went wrong! There was a malloc error.\n");
			return (-1);
		}
		free(input);
	}
	return (0);
}
