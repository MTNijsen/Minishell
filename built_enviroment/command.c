#include "../minishell.h"

int isbuiltin(char *str)
{
	if (!ft_strncmp(str, "cd", 3) || !ft_strncmp(str, "echo", 5) || !ft_strncmp(str, "env", 4)\
	|| !ft_strncmp(str, "exit", 5) || !ft_strncmp(str, "export", 7) || !ft_strncmp(str, "pwd", 4)\
	|| !ft_strncmp(str, "unset", 6))
		return (1);
	return (0);
}

int builtin(t_token *node, t_env *env_node, bool pipe_present)
{
	if (!ft_strncmp(node->value, "cd", 3))
		return (bi_cd(node, env_node));
	else if (!ft_strncmp(node->value, "echo", 5))
		return (bi_echo(node));
	else if (!ft_strncmp(node->value, "env", 4))
		return (bi_env(env_node));
	else if (!ft_strncmp(node->value, "exit", 5))
		return (bi_exit(pipe_present));
	else if (!ft_strncmp(node->value, "export", 7))
		return (bi_export(node, env_node));
	else if (!ft_strncmp(node->value, "pwd", 4))
		return (bi_pwd(env_node));
	else if (!ft_strncmp(node->value, "unset", 6))
		return (bi_unset(node, env_node));
	return (0);
}

//returns -1 if error, returns pid if succesfully forked incase no pipe present
int command(t_token *node, t_env *env_node, bool pipe_present , int *pid)
{
	char	**args;
	char	**envp;

	if (access(node->value, X_OK))
		return (errno);
	envp = list_to_env(env_node);
	if (!envp)
		return (MALLOC_FAILURE);
	args = tokens_to_args(node);
	if (!args)
		return (free_array(envp), MALLOC_FAILURE);
	if (!pipe_present)
	{
		*pid = fork();
		if (*pid)
			return (*pid);
	}
	execve(args[0], args, envp);
	return (0);
}