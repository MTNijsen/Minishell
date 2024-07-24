#include "../minishell.h"

static int isbuiltin(char *str)
{
	if (!ft_strncmp(str, "cd", 3) || !ft_strncmp(str, "echo", 5) || !ft_strncmp(str, "env", 4)\
	|| !ft_strncmp(str, "exit", 5) || !ft_strncmp(str, "export", 7) || !ft_strncmp(str, "pwd", 4)\
	|| !ft_strncmp(str, "unset", 6))
		return (1);
	return (0);
}

static int builtin(t_output *node, t_env *env_node, bool is_child)
{
	if (!ft_strncmp(node->node, "cd", 3))
		return (bi_cd(node, env_node));
	else if (!ft_strncmp(node->node, "echo", 5))
		return (bi_echo(node));
	else if (!ft_strncmp(node->node, "env", 4))
		return (bi_env(env_node));
	else if (!ft_strncmp(node->node, "exit", 5))
		return (bi_exit(is_child));
	else if (!ft_strncmp(node->node, "export", 7))
		return (bi_export(node, env_node));
	else if (!ft_strncmp(node->node, "pwd", 4))
		return (bi_pwd(env_node));
	else if (!ft_strncmp(node->node, "unset", 6))
		return (bi_unset(node, env_node));
	return (0);
}

//returns -1 if error, returns pid if succesfully forked incase no pipe present
int command(char **node, t_env *env_node, bool is_child)
{
	char	*cmd;
	int		pid;
	// char	**args;
	char	**envp;

	cmd = node[0];
	if (access(cmd, X_OK))
	{
		write(2, "You do not have executing access to this command\n", 50);
		return (1);
	}
	envp = list_to_array(env_node);
	if (!envp)
		return (MALLOC_FAILURE);
	// args = list_to_args(node);
	// if (!args)
	// 	return (free_array(envp), MALLOC_FAILURE);
	if (!is_child)
	{
		pid = fork();
		if (pid)
			return (free_array(envp), pid);
	}
	execve(cmd, node, envp);
	return (0);
}

int execute_section(t_output *first_node, t_env *env_node, bool is_child)
{
	t_output *node;

	node = first_node;
	while (node != NULL)
	{
		if (node->type_node == MINI_REDIRECT)
			if (redirect(node))
				return (1);
		node = node->next_node;
	}
	node = first_node;
	while (node != NULL && node->type_node == MINI_REDIRECT)
		node->next_node;
	if (node != NULL && isbuiltin(node->node))
		return (builtin(node, env_node, is_child));
	else if (node != NULL)
		return (command(node, env_node, is_child));
	return (0); //only reaches this if only redirects are in this section whilst legal its useless
}


//assuming nestled nodes
//attach to the front signal handling
int executor(t_output *first_node, t_env *env_node)
{
	t_output	*node;
	bool		pipe_present;
	int			pid;
	static int	buf;

	node = first_node;
	pipe_present = false;
	while (node != NULL)
	{
		if (node->type_node == MINI_PIPE)
		{
			pipe_present = true;
			pid = pipe_line();
			if (pid == 0)
				execute_section(node->next_node, env_node, true); //check for fail
		}
		node = node->next_node;
	}
	if (pipe_present == true) //the right side of a pipe is also a child process
		pid = fork();
	if (pid == 0)
		buf = execute_section(node, env_node, pipe_present) << 8;
	if (waitpid(pid, &buf, 0) != -1)
	{
		if  (WIFEXITED(buf))
			buf = WEXITSTATUS(buf);
		else
			buf = WTERMSIG(buf);
	}
	while (waitpid (-1, NULL, 0))
		;
	return (buf);
}



/*
go over nodes first seeing what is a pipe, if found go to check in that 
section for redirects which does it stuff file descriptors should now be sorted

then to the executing stage where command/builtin is run with everything left in that section being its argv (including flags)
*/