#include "../minishell.h"

int add_env(t_env *node, char *name, char *content, bool heap)
{
	while(node->next != NULL)
		node = node->next;
	node->next = (t_env *)malloc(sizeof(t_env));
	if (!node->next)
		return (MALLOC_FAILURE);
	node = node->next;
	node->next = NULL;
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

//make it so it can handle no startnode present by just making a new enviroment
int	modify_env(t_env *start_node, char *name, char *content, bool heap)
{
	t_env	*c_node;

	c_node = start_node;
	if (!name || !c_node)
		return (1);
	while(c_node->next != NULL)
	{
		if (!ft_strncmp(c_node->next->name, name, ft_strlen(name) +1))
		{
			c_node = c_node->next;
			free(c_node->content);
			c_node->content = NULL;
			break ;
		}
		c_node = c_node->next;
	}
	if (c_node->next == NULL)
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
	node->next = NULL;
	node->content = content;
	return (node);
}

int	remove_env(t_env *node, char *name)
{
	t_env	*remove_node;

	if (!node || !name)
		return (1);
	while(node != NULL)
	{
		if (!ft_strncmp(node->next->name, name, -1))
		{
			remove_node = node->next;
			node->next = remove_node->next;
			free(remove_node->content);
			free(remove_node->name);
			free(remove_node);
			return (0);
		}
		node = node->next;
	}
	return (0);
}

char *return_env(t_env *node, char *name)
{
	if (!node || !name)
		return (NULL);
	while(node != NULL)
	{
		if (!ft_strncmp(node->name, name, -1))
			return (node->content);
		node = node->next;
	}
	return (NULL);
}
