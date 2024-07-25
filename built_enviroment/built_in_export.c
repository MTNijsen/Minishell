#include "../minishell.h"

//needs to display in a sorted way
//could create a duplicate list to sort with bubble or some wack
static int export_display(t_env *env_node)
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
	return (0);
}

//should move to its own file since its reused in list to array;
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

static int add_export(t_token *current_token, t_env *env_node)
{
	char *split[2];

	while (current_token != NULL)
	{
		split[0] = NULL;
		split[1] = NULL;
		if (!valid_export(current_token->value))
			return (-1);
		split_env(current_token->value, &split[0], &split[1]);
		if (modify_env(env_node, split[0], split[1], 1))
			return (free_env(env_node), -1);
		current_token = current_token->next;
	}
	return (0);
}

int bi_export(const t_token *token, t_env *env_node)
{
	t_token	*current_token;

	if (token == NULL || env_node == NULL)
		return (1);
	current_token = token->next;
	if (current_token->value == NULL)
		return (export_display(env_node)); //what exit code?
	return (add_export(current_token, env_node)); //what exit code?
}
