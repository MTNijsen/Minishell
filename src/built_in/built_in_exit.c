/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:28 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 16:51:29 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//CLEAN UPPPPP!!!!
void bi_exit(char **argv, t_data *data, bool pipe_present)
{
	if (!pipe_present)
		printf("exit\n");
	if (argv[1] != NULL)
		clean_exit(data, ft_atoi(argv[1]));
	clean_exit(data, 0);
}