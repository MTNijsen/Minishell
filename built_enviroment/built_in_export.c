#include "../minishell.h"

//bash displays in a sorted list but not needed
//all our variables in t_env are export variables thus its the same as env outside of format
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
		node = node->next;
	}
}

//should move to its own file since its reused in list to array;
int	split_env(char *arg, char **output1, char **output2)
{
	int	i;
	int len1;

	i = -1;
	len1 = -1;
	while (arg[++i])
	{
		if (arg[i] == '=' && len1 == -1)
			len1 = i +1;
	}
	if (len1 == -1)
		len1 = i +1;
	*output1 = (char *)malloc(sizeof(char) * len1);
	if (!output1)
		return (MALLOC_FAILURE);
	ft_strlcpy(*output1, arg, len1);
	if (len1 != i +1)
	{
		*output2 = (char *)malloc(sizeof(char) * (i - len1 +1));
		if (!output2)
			return (free(output1), MALLOC_FAILURE);
		ft_strlcpy(*output2, &arg[len1], i - len1 +1);
	}
	return (0);
}

static int valid_export(char *arg)
{
	int	i;

	i = 0;
	if (ft_isdigit(arg[0]))
		return (0);
	while (arg[++i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]))
			return (0);
	}
	return (1);
}

static int add_export(char **argv, t_env *env_node)
{
	char	*split[2];
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		split[0] = NULL;
		split[1] = NULL;
		if (!valid_export(argv[i]))
			return (1);
		split_env(argv[i], &split[0], &split[1]);
		if (modify_env(env_node, split[0], split[1], 1))
			return (free_env(env_node), MALLOC_FAILURE);
		i++;
	}
	return (0);
}

int bi_export(const char **argv, t_env *env_node)
{
	if (argv[1] == NULL)
	{
		export_display(env_node);
		return (0);
	}
	else
		return (add_export(argv, env_node));
}
