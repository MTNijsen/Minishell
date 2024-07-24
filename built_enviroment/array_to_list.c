#include "../minishell.h"

t_env *array_to_list(char **envp)
{
	t_env	*start_node;
	char	*split[2];
	int		i;

	start_node = NULL;
	if (!envp)
		return (NULL);
	i = -1;
	if (split_env(envp[++i], &split[0], &split[1]))
			return (NULL);
	start_node = creat_env(split[0], split[1]);
	if (!start_node)
		return (NULL);
	while (envp[++i])
	{
		if (split_env(envp[i], &split[0], &split[1]))
			return (free_env(start_node), NULL);
		if (modify_env(start_node, split[0], split[1], 1))
			return (free_env(start_node), NULL);
	}
	return (start_node);
}