/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipeline.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:04 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 16:52:36 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

int	pipeline(void)
{
	int	pipe_ids[2];
	int	pid;

	if (pipe(pipe_ids) == -1)
		return (perror("pipe"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), close(pipe_ids[0]), close(pipe_ids[1]), -1);
	if (pid == 0)
	{
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
