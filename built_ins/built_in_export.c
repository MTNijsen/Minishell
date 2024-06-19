#include "minishell.h"

//needs to display in a sorted way
static void export_display(t_env *env_node)
{
	t_env *node;
	
	node = env_node;
	while(node != NULL)
	{
		if (node->content != NULL)
			printf("%s=\"%s\"\n", node->name, node->content);
		else
			printf("%s\n", node->name);
		node = node->next_node;
	}
}
int	split_env(char *str, char **output1, char **output2)
{
	int	i;
	int len1;

	i = -1;
	len1 = -1;
	while (str[++i])
	{
		if (str[i] == '=' && len1 == -1)
			len1 = i +1;
	}
	if (len1 == -1)
		len1 = i;
	*output1 = (char *)malloc(sizeof(char) * len1);
	if (!output1)
		return (MALLOC_FAILURE);
	ft_strlcpy(*output1, str, len1);
	if (len1 != i)
	{
		*output2 = (char *)malloc(sizeof(char) * (i - len1 +1));
		if (!output2)
			return (free(output1), MALLOC_FAILURE);
		ft_strlcpy(*output2, &str[len1], i - len1 +1);
	}
	return (0);
}

static int valid_export(char **args)
{
	int	i;
	int j;

	i = 0;
	while (args[++i])
	{
		j = -1;
		if (ft_isdigit(args[i][0]))
			return (1);
		while(args[i][++j])
		{
			if (!ft_isalnum(args[i][j]))
				return (1);
		}
	}
	return (0);
}

static int add_export(char **args, t_env *env_node)
{
	char *split[2];
	int	i;

	i = 0;
	while (args[++i])
	{
		split[0] = NULL;
		split[1] = NULL;
		if (!valid_export(args[i]))
			return (-1);
		split_env(args[i], &split[0], &split[1]);
		if (!split)
			return (free_env(env_node), -1);
		if (modify_env(env_node, split[0], split[1], 1))
			return (free_env(env_node), -1);
	}
	return (0);
}

int bi_export(char **args, t_env *env_node)
{
	int	i;
	char **output;

	if (args == NULL || args[0] == NULL || env_node == NULL)
		return (1);
	if (args[1] == NULL)
		export_display(env_node);
	else
		return (add_export(args, env_node));
	return (0);
}
