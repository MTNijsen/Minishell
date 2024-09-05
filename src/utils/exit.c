/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 15:03:57 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/04 19:14:16 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

void wait_exit(int pid, int *exit_code)
{
	if (pid != -1 && waitpid(pid, exit_code, 0) != -1)
	{
		if  (WIFEXITED(*exit_code))
			*exit_code = WEXITSTATUS(*exit_code);
		else
			*exit_code = WTERMSIG(*exit_code);
	}
}

void clean_exit(t_data *data, int exit_status)
{
	free_struct(data);
	exit(exit_status);
}