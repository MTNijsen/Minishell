#include "../minishell.h"

static void unset(char *name , t_env **env_node)
{
	t_env *node;
	t_env *next;

	node = *env_node;
	if (!ft_strncmp(node->name, name, ENV_VARIABLE_LENGTH))
	{
		*env_node = node->next;
		free(node->content);
		free(node->name);
		free(node);
		return ;
	}
	while (node->next != NULL && ft_strncmp(node->next->name, name, ENV_VARIABLE_LENGTH))
		node = node->next;
	if (node->next && !ft_strncmp(node->next->name, name, ENV_VARIABLE_LENGTH))
	{
		next = node->next->next;
		free(node->next->content);
		free(node->next->name);
		free(node->next);
		node->next = next;
	}
}

//unsets all token.values found except first which is the command
int	bi_unset(const t_token *token, t_env *env_node)
{
	t_token *current_token;

	current_token = token->next;
	while (current_token != NULL)
		unset(current_token->value, &env_node);
	return (0);
}
