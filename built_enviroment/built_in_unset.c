#include "../minishell.h"

static void unset(char *name , t_env **env_node)
{
	t_env *node;
	t_env *next_node;

	node = *env_node;
	if (!ft_strncmp(node->name, name, ENV_VARIABLE_LENGTH))
	{
		*env_node = node->next_node;
		free(node->content);
		free(node->name);
		free(node);
		return ;
	}
	while (node->next_node != NULL && ft_strncmp(node->next_node->name, name, ENV_VARIABLE_LENGTH))
		node = node->next_node;
	if (node->next_node && !ft_strncmp(node->next_node->name, name, ENV_VARIABLE_LENGTH))
	{
		next_node = node->next_node->next_node;
		free(node->next_node->content);
		free(node->next_node->name);
		free(node->next_node);
		node->next_node = next_node;
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
