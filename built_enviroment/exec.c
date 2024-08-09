#include "../minishell.h"

static int command(t_proc *proc, t_data *data, bool pipe_present, int *pid)
{
	if (!ft_strncmp(proc->cmd, "cd", 3))
		return (bi_cd(proc->argv, data));
	else if (!ft_strncmp(proc->cmd, "echo", 5))
		return (bi_echo(proc->argv), 0);
	else if (!ft_strncmp(proc->cmd, "env", 4))
		return (bi_env(data), 0);
	else if (!ft_strncmp(proc->cmd, "exit", 5))
		return (bi_exit(proc->argv, data, pipe_present), 0);
	else if (!ft_strncmp(proc->cmd, "export", 7))
		return (bi_export(proc->argv, data), 0);
	else if (!ft_strncmp(proc->cmd, "pwd", 4))
		return (bi_pwd(data));
	else if (!ft_strncmp(proc->cmd, "unset", 6))
		return (bi_unset(proc->argv, data), 0);
	if (access(proc->cmd, X_OK))
		return (errno);
	if (!pipe_present)
	{
		*pid = fork();
		if (*pid)
			return (0);
	}
	execve(proc->cmd, proc->argv, data->envp);
	return (0);
}

static int execute_section(t_proc *proc, t_data *data, int *pid, bool pipe_present)
{
	int		exit_code;

	exit_code = redirect(proc);
	if (exit_code)
		return (exit_code);
	exit_code = command(proc, data, pipe_present, pid);
	return (exit_code);
}

static int exec_exit(int pid, int exit_code)
{
	wait_exit(pid, &exit_code);
	while (waitpid (-1, NULL, 0) != -1)
		;
	dup2(STDIN_CLONE, STDIN_FILENO);
	return (exit_code);
}

static t_proc *exec_pipes(t_data *data)
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

int executor(t_data *data)
{
	int 		exit_code;
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