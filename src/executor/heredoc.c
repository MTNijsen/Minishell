/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:08 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 17:06:15 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//on ctrl-d could give a warning
static void	heredoc_read(char *delimiter, t_proc *proc, t_data *data)
{
	char	*buf;

	set_sig(S_HEREDOC);
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
	clean_exit(data, EXIT_SUCCESS);
}

int	proc_here(t_data *data, t_proc *proc, t_token *redir)
{
	int	pid;
	int	exit_code;

	exit_code = 0;
	if (pipe(proc->hd_pipe) == -1)
		return (COMMON_ERROR);
	pid = fork();
	if (pid == -1)
		return (COMMON_ERROR);
	if (pid == 0)
		heredoc_read(redir->value, proc, data);
	close(proc->hd_pipe[1]);
	wait_exit(pid, &exit_code, S_HEREDOC);
	if (exit_code != 0)
		return (exit_code);
	return (0);
}

int	heredoc(t_data *data)
{
	int		exit_code;
	t_token	*redir;
	t_proc	*proc;

	exit_code = 0;
	proc = data->procs;
	while (proc != NULL)
	{
		redir = proc->redirs;
		while (redir)
		{
			if (redir->type == HEREDOC)
			{
				exit_code = proc_here(data, proc, redir);
			}
			redir = redir->next;
		}
		proc = proc->next;
	}
	return (exit_code);
}
