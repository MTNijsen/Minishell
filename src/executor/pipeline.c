/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipeline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:04 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/04 19:46:32 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>
#include <errno.h>

int	pipeline(void)
{
	int	pipe_ids[2];
	int	pid;

	if (pipe(pipe_ids) == -1)
		return (errno);
	pid = fork();
	if (pid == -1)
		return (close(pipe_ids[0]), close(pipe_ids[1]), errno);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		close(pipe_ids[0]);
		dup2(pipe_ids[1], STDOUT_FILENO);
		close(pipe_ids[1]);
		return (pid);
	}
	close(pipe_ids[1]);
	dup2(pipe_ids[0], STDIN_FILENO);
	close(pipe_ids[0]);
	return (pid);
}
