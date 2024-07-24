#include "../minishell.h"

//needs to display in a sorted way
//could create a duplicate list to sort with bubble or some wack
static void export_display(t_env *env_node)
{
	t_env *node;
	
	node = env_node;
	while(node != NULL)
	{
		if (node->content != NULL)
			printf("-x declare %s=\"%s\"\n", node->name, node->content);
		else
			printf("-x decalre %s\n", node->name);
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
		len1 = i +1;
	*output1 = (char *)malloc(sizeof(char) * len1);
	if (!output1)
		return (MALLOC_FAILURE);
	ft_strlcpy(*output1, str, len1);
	if (len1 != i +1)
	{
		*output2 = (char *)malloc(sizeof(char) * (i - len1 +1));
		if (!output2)
			return (free(output1), MALLOC_FAILURE);
		ft_strlcpy(*output2, &str[len1], i - len1 +1);
	}
	return (0);
}

static int valid_export(char *args)
{
	int	i;

	i = 0;
	if (ft_isdigit(args[0]))
		return (0);
	while (args[++i] && args[i] != '=')
	{
		if (!ft_isalnum(args[i]))
			return (0);
	}
	return (1);
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
		if (modify_env(env_node, split[0], split[1], 1))
			return (free_env(env_node), -1);
	}
	return (0);
}
//need to take segments instead of array
int bi_export(char **args, t_env *env_node)
{
	if (args == NULL || args[0] == NULL || env_node == NULL)
		return (1);
	if (args[1] == NULL)
		export_display(env_node);
	return (add_export(args, env_node));
}
