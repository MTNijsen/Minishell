/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/10 14:51:10 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static void	heredoc_read(char *delimiter, t_proc *proc, t_data *data)
{
	char	*buf;

	buf = readline("heredoc> ");
	while (buf != NULL)
	{
		if (ft_strncmp(buf, delimiter, ft_strlen(delimiter)) == 0)
			clean_exit(data, EXIT_SUCCESS);
		write(proc->hd_pipe[1], buf, ft_strlen(buf));
		write(proc->hd_pipe[1], "\n", 1);
		free(buf);
		buf = readline("heredoc> ");
	}
	clean_exit(data, EXIT_FAILURE);
}

int	heredoc(t_data *data)
{
	int		pid;
	int		exit_code;
	t_token	*redir;
	t_proc	*proc;

	proc = data->procs;
	exit_code = 0;
	while (proc != NULL)
	{
		redir = proc->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC)
			{
				if (pipe(proc->hd_pipe) == -1)
					return (errno);
				pid = fork();
				if (pid == -1)
					return (errno);
				if (pid == 0)
					heredoc_read(redir->value, proc, data);
				close(proc->hd_pipe[1]);
				wait_exit(pid, &exit_code);
				if (exit_code != 0)
					return (exit_code);
			}
			redir = redir->next;
		}
		proc = proc->next;
	}
	return (exit_code);
}
