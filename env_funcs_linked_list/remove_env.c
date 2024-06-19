#include "../minishell.h"

int	remove_env(t_env *node, char *name)
{
	t_env	*remove_node;

	if (!node || !name)
		return (1);
	while(node != NULL)
	{
		if (!ft_strcmp(node->next_node->name, name))
		{
			remove_node = node->next_node;
			node->next_node = remove_node->next_node;
			free(remove_node->content);
			free(remove_node->name);
			free(remove_node);
			return (0);
		}
		node = node->next_node;
	}
	return (0);
}