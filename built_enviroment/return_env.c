#include "../minishell.h"

char *return_env(t_env *node, char *name)
{
	if (!node || !name)
		return (NULL);
	while(node != NULL)
	{
		if (!ft_strncmp(node->name, name, -1))
			return (node->content);
		node = node->next_node;
	}
	return (NULL);
}