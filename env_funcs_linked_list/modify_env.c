#include "../minishell.h"

//it is assumed name and content dont exist on a local scope
int	modify_env(t_env *node, char *name, char *content, bool export)
{
	if (!node || !name)
		return (1);
	while(node != NULL)
	{
		if (ft_strcmp(node->name,name))
		{
			free(node->content);
			break ;
		}
		node = node->next_node;
	}
	if (node == NULL)
	{
		node = (t_env *)malloc(sizeof(t_env));
		if (!node)
			return (1);
		node->name = name;
		node->export = export;
	}
	node->content = content;
	return (0);
}
