/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 15:03:57 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 18:20:55 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void	wait_exit(int pid, int *exit_code, t_sign child)
{
	if (pid != -1 && waitpid(pid, exit_code, 0) != -1)
	{
		if (g_sign == SIGINT)
		{
			*exit_code += 128;
			g_sign = 0;
		}
		else if (WIFEXITED(*exit_code))
			*exit_code = WEXITSTATUS(*exit_code);
		else if (child == S_HEREDOC)
			write(1, "\n", 1);
		else if (child == S_CHILD && *exit_code == SIGQUIT)
			write(1, "Quit (core dumped)", 19);
	}
	dup2(STDIN_CLONE, STDIN_FILENO);
	dup2(STDOUT_CLONE, STDOUT_FILENO);
}

void	clean_exit(t_data *data, int exit_status)
{
	free_data(data);
	close(STDIN_CLONE);
	close(STDOUT_CLONE);
	exit(exit_status);
}
