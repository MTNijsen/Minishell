#include "../minishell.h"

static int	redirect_in(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_RDONLY);
	if (!fd)
		return (errno);
	dup2(fd, 0);
	close(fd);
	return (0);
}

static int	redirect_out(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
		return (errno);
	dup2(fd, 1);
	close(fd);
	return (0);
}

static int	redirect_out_append(t_redir *redir)
{
	int	fd;

	fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (!fd)
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

	while (proc->redir != NULL)
	{
		if (proc->redir->type == IN_REDIRECT)
			exit_code = (redirect_in(proc->redir));
		else if (proc->redir->type == OUT_REDIRECT)
			exit_code = (redirect_out(proc->redir));
		else if (proc->redir->type == APP_REDIRECT)
			exit_code = (redirect_out_append(proc->redir));
		else if (proc->redir->type == HEREDOC)
			exit_code = (redirect_heredoc(proc));
		if (exit_code != 0)
			return (exit_code);
		proc->redir = proc->redir->next;
	}
	return (exit_code);
}
