/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:01 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 16:51:03 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static int	redirect_in(t_token *redir)
{
	int	fd;

	fd = open(redir->value, O_RDONLY);
	if (fd == -1)
		return (errno);
	dup2(fd, 0);
	close(fd);
	return (0);
}

static int	redirect_out(t_token *redir)
{
	int	fd;

	fd = open(redir->value, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (errno);
	dup2(fd, 1);
	close(fd);
	return (0);
}

static int	redirect_out_append(t_token *redir)
{
	int	fd;

	fd = open(redir->value, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return (errno);
	dup2(fd, 1);
	close(fd);
	return (0);
}

static int	redirect_heredoc(t_proc *proc)
{
	dup2(proc->hd_pipe[0], 0);
	close(proc->hd_pipe[0]);
	return (0);
}

//steps through t_token list till next PIPE and handles any redirections found
//exit code should be checked and first_token needs to be freed if it breaks
int	redirect(t_proc *proc)
{
	int exit_code;

	exit_code = 0;
	while (proc->redirs != NULL)
	{
		if (proc->redirs->type == IN_REDIRECT)
			exit_code = (redirect_in(proc->redirs));
		else if (proc->redirs->type == OUT_REDIRECT)
			exit_code = (redirect_out(proc->redirs));
		else if (proc->redirs->type == APP_REDIRECT)
			exit_code = (redirect_out_append(proc->redirs));
		else if (proc->redirs->type == HEREDOC)
			exit_code = (redirect_heredoc(proc));
		if (exit_code != 0)
			return (exit_code);
		proc->redirs = proc->redirs->next;
	}
	return (exit_code);
}
