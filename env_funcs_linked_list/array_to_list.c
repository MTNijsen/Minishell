#include "../minishell.h"

t_env *array_to_list(char **envp)
{
	t_env	*start_node;
	char	*split[2];
	int		i;

	if (!envp)
		return (NULL);
	i = -1;
	while (envp[++i])
	{
		if (split_env(envp[i], &split[0], &split[1]))
			return (free_env(start_node), NULL);
		if (modify_env(start_node, split[0], split[1], 1))
			return (free_env(start_node), NULL);
		free(split);
	}
	return (start_node);
}