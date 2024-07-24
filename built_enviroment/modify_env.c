#include "../minishell.h"

int add_env(t_env *node, char *name, char *content, bool heap)
{
	while(node->next_node != NULL)
		node = node->next_node;
	node->next_node = (t_env *)malloc(sizeof(t_env));
	if (!node->next_node)
		return (MALLOC_FAILURE);
	node = node->next_node;
	node->next_node = NULL;
	if (heap == 1)
		node->name = name;
	else
	{
		node->name = ft_strdup(name);
		if (!node->name)
			return (MALLOC_FAILURE);
	}
	node->content = content;
	return (0);
}

//it is assumed name and content dont exist on a local scope
int	modify_env(t_env *start_node, char *name, char *content, bool heap)
{
	t_env	*c_node;

	c_node = start_node;
	if (!name)
		return (1);
	while(c_node->next_node != NULL)
	{
		if (!ft_strncmp(c_node->next_node->name, name, ft_strlen(name) +1))
		{
			c_node = c_node->next_node;
			free(c_node->content);
			c_node->content = NULL;
			break ;
		}
		c_node = c_node->next_node;
	}
	if (c_node->next_node == NULL)
		return (add_env(c_node, name, content, heap));
	c_node->content = content;
	return (0);
}

t_env *creat_env(char *name, char *content)
{
	t_env *node;

	if (!name)
		return (NULL);
	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->name = name;
	node->next_node = NULL;
	node->content = content;
	return (node);
}
