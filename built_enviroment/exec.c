#include "../minishell.h"

static int execute_section(t_token *first_token, t_env *env_node, t_exec info, int *pid)
{
	t_token *token;
	int		exit_code;

	exit_code = 0;
	token = first_token;
	while (token->next != NULL && token->next->type != PIPE)
		token = token->next;
	token->next = NULL;
	token = redirect(first_token, NULL, info.index, &exit_code);
	if (exit_code)
		return (exit_code);
	if (isbuiltin(token->value))
		return (builtin(token, env_node, info.pipe_present));
	else
		return (command(token, env_node, info.pipe_present, pid));
}

static int exec_exit(int pid, int exit_code)
{
	int	buf;
	
	buf = 0;
	if (waitpid(pid, &buf, 0) != -1)
	{
		if  (WIFEXITED(buf))
			buf = WEXITSTATUS(buf);
		else
			buf = WTERMSIG(buf);
	}
	else
		buf = exit_code;
	while (waitpid (-1, NULL, 0) != -1)
		;
	reset_std_fd();
	return (buf);
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
				free_env(env_node);
				free_tokens(start_sec);
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
//needs to be shortened

int executor(t_token *token, t_env *env_node)
{
	t_exec		info;
	int 		exit_code;
	int			pid;

	info.index = 0;
	info.pipe_present = false;
	exit_code = 0;
	pid = 0;
	token = exec_pipes(token, env_node, &info);
	if (info.pipe_present == true)
	{
		pid = fork();
		if (pid == 0)
		{
			exit_code = execute_section(token, env_node, info, &pid);
			free_env(env_node);
			free_tokens(token);
			exit (exit_code);
		}
	}
	else
		exit_code = execute_section(token, env_node, info, &pid); //if section is a command pid is a non-zero value
	return (free_tokens(token), exec_exit(pid, exit_code));
}