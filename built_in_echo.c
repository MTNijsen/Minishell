#include "minishell.h"

int	find_flags(t_output *node)
{
	int	i;
	int output;

	i = 0;
	while(node->type_node == MINI_FLAG)
	{
		while (node->node[i] == 'n')
			i++;
		if (node->node[i])
			return (0);
		node = node->next_node;
	}
	return (1);
}

char *echo(t_output *node, char *envp[])
{
	int		flags;
	char	*output;
	
	flags = find_flags(node->next_node);


	if (flags)
		return (output);
	return (strappend(output, "\n"));
}