#include "../minishell.h"

char **list_to_array(t_env *node)
{
	int		i;
	char	**envp;
	char	*output;

	if (!node)
		return (NULL);
	i = 0;
	while(node != NULL && ++i)
		node = node->next_node;
	envp = (char **)ft_calloc(i +1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = -1;
	while(node != NULL)
	{
		if (node->export == 0)
		{
			output = ft_strappend(node->content, "=", node->name);
			if (!output)
				return (free_array(envp), NULL);
			envp[++i] = output;
		}
		node = node->next_node;
	}
	return (envp);
}
