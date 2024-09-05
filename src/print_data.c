/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 17:11:52 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 17:24:23 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_data(t_data *data)
{
	printf("POINTER PROCS: %p\n", data->procs);
	// printf("PROC_COUNT: %i\n", data->proc_count);
	printf("POINTER TOKENS: %p\n", data->tokens);
	// printf("TOKEN_COUNT: %i\n", data->token_count);
	printf("INPUT: %s\n", data->input);
}
