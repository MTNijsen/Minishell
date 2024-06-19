#include "../minishell.h"

void	free_env(t_env	*node)
{
	t_env	*next_node;

	while (node != NULL)
	{
		next_node = node->next_node;
		free(node->content);
		free(node->name);
		free(node);
		node = next_node;
	}
}