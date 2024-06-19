#include "../minishell.h"

/*does not need to take arguments like in bash, what if no envp*/
int bi_env(t_env *env_node)
{
	t_env *node;

	if (env_node == NULL)
		return (1);
	node = env_node;
	while(node != NULL)
	{
		if (node->content)
			printf("%s=%s\n", node->name, node->content);
		else
			printf("%s\n");
		node = node->next_node;
	}
	return (0);
}
