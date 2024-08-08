#include "../minishell.h"

static int execute_section(t_proc *proc, t_env *env_node, t_exec info, int *pid)
{
	t_token *token;
	int		exit_code;

	exit_code = 0;
	token = first_token;
	while (token->next != NULL && token->next->type != PIPE)
		token = token->next;
	token->next = NULL; //is this needed or not already done in exec pipes
	token = redirect(first_token, info.h_doc, info.index, &exit_code);
	if (exit_code)
		return (free(first_token), exit_code);
	if (isbuiltin(token->value))
		exit_code = builtin(token, env_node, info.pipe_present);
	else
		exit_code = command(token, env_node, info.pipe_present, pid);
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

static t_token *exec_pipes( t_token *token, t_env *env_node, t_exec *info)
{
	t_token 	*start_sec;
	t_token 	*temp_token;
	int			pid;
	int			exit_code;

	start_sec = token;
	while (token != NULL && token->next != NULL)
	{
		if (token->next->type == PIPE)
		{
			info->pipe_present = true;
			temp_token = token;
			token = token->next->next;
			free_token(temp_token->next);
			temp_token->next = NULL;
			pid = pipeline();
			if (pid == 0)
			{
				exit_code = execute_section(start_sec, env_node, *info, &pid);
				free_tokens(start_sec);
				free_env(env_node);
				free_tokens(token);
				exit (exit_code);
			}
			info->index++;
			free_tokens(start_sec);
			start_sec = token;
		}
		else
			token = token->next;
	}
	return (start_sec);
}

int executor(t_proc *proc, char ***envp)
{
	int 		exit_code;
	int			pid;
	int			index;

	pid = -1;
	exit_code = heredoc_read(proc);
	if (exit_code != 0)
		return (exit_code);
	index = exec_pipes(proc, envp);
	if (index != 0)
	{
		pid = fork();
		if (pid == -1)
			return (errno);
		if (pid == 0)
		{
			exit_code = execute_section(proc, envp, &pid);
			free_processes(proc);
			free_array(envp);
			exit (exit_code);
		}
	}
	else
		exit_code = execute_section(proc[0], envp, &pid); //if section is a command pid is a non-zero value
	return (exec_exit(pid, exit_code));
}
