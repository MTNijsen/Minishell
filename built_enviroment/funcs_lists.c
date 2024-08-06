#include "../minishell.h"

char **list_to_env(t_env *node)
{
	int		i;
	char	**envp;
	char	*output;
	t_env	*start_node;

	start_node = node;
	if (!node)
		return (NULL);
	i = 0;
	while(node != NULL && ++i)
		node = node->next_node;
	envp = (char **)ft_calloc(i +1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = -1;
	node = start_node;
	while(node != NULL)
	{
		output = ft_triappend(node->name, "=", node->content);
		if (!output)
			return (free_array(envp), NULL);
		envp[++i] = output;
		node = node->next_node;
	}
	return (envp);
}

char **tokens_to_args(t_token *node)
{
	int		i;
	char	**args;
	char	*output;
	t_token	*start_node;

	start_node = node;
	if (!node)
		return (NULL);
	i = 0;
	while(node != NULL && ++i)
		node = node->next;
	args = (char **)ft_calloc(i +1, sizeof(char *));
	if (!args)
		return (NULL);
	i = -1;
	node = start_node;
	while(node != NULL)
	{
		output = ft_strdup(node->value);
		if (!output)
			return (free_array(args), NULL);
		args[++i] = output;
		node = node->next;
	}
	return (args);
}

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
