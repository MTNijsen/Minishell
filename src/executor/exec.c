/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:12 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/16 18:11:46 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

static int	command(t_proc *proc, t_data *data, bool pipe_present, int *pid)
{
	char	**envp;
	char	**argv;
	
	if (!ft_strncmp(proc->argv[0], "cd", 3))
		return (bi_cd(proc->argv, data));
	else if (!ft_strncmp(proc->argv[0], "echo", 5))
		return (bi_echo(proc->argv), 0);
	else if (!ft_strncmp(proc->argv[0], "env", 4))
		return (bi_env(data), 0);
	else if (!ft_strncmp(proc->argv[0], "exit", 5))
		return (bi_exit(proc->argv, data, pipe_present), 0);
	else if (!ft_strncmp(proc->argv[0], "export", 7))
		return (bi_export(proc->argv, data), 0);
	else if (!ft_strncmp(proc->argv[0], "pwd", 4))
		return (bi_pwd(data));
	else if (!ft_strncmp(proc->argv[0], "unset", 6))
		return (bi_unset(proc->argv, data), 0);
	if (get_path(data, proc))
		return (errno);
	if (!pipe_present)
	{
		*pid = fork();
		if (*pid)
			return (0);
	}
	envp = data->envp;
	copy_array(&argv, proc->argv);
	free_struct(data);
	free(data);
	set_sig(S_CHILD);
	execve(argv[0], argv, envp);
	return (0);
}

static int	execute_section(t_proc *proc, t_data *data, \
	int *pid, bool pipe_present)
{
	int		exit_code;

	exit_code = redirect(proc);
	if (exit_code != 0)
		return (exit_code);
	if (proc->argv && proc->argv[0])
		exit_code = command(proc, data, pipe_present, pid);
	return (exit_code);
}

static int	exec_exit(int pid, int exit_code)
{
	wait_exit(pid, &exit_code, S_CHILD);
	while (waitpid (-1, NULL, 0) != -1)
		;
	dup2(STDIN_CLONE, STDIN_FILENO);
	dup2(STDOUT_CLONE, STDOUT_FILENO);
	return (exit_code);
}

static t_proc	*exec_pipes(t_data *data)
{
	t_proc	*proc;
	int		pid;
	int		exit_code;

	proc = data->procs;
	while (proc->next)
	{
		pid = pipeline();
		if (pid == 0)
		{
			exit_code = execute_section(proc, data, &pid, true);
			clean_exit(data, exit_code);
		}
		proc = proc->next;
	}
	return (proc);
}

int	executor(t_data *data)
{
	int			exit_code;
	int			pid;
	t_proc		*last_proc;

	pid = -1;
	exit_code = heredoc(data);
	if (exit_code != 0)
		return (exit_code);
	last_proc = exec_pipes(data);
	if (&last_proc == &data->procs)
	{
		pid = fork();
		if (pid == -1)
			return (errno);
		if (pid == 0)
		{
			exit_code = execute_section(last_proc, data, &pid, true);
			clean_exit(data, exit_code);
		}
	}
	else
		exit_code = execute_section(last_proc, data, &pid, false);
	return (exec_exit(pid, exit_code));
}
