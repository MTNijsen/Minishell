#include "../minishell.h"

void	free_env(t_env	*node)
{
	t_env	*next_node;

	while (node != NULL)
	{
		next_node = node->next_node;
		free(node->content);
		free(node->name);
		free(node);
		node = next_node;
	}
}
void	free_array(char	**array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_token(t_token *token)
{
	free(token->value);
	free(token);
}

void	free_tokens(t_token *token)
{
	t_token *temp_token;

	while (token != NULL)
	{
		temp_token = token->next;
		free(token->value);
		free(token);
		token = temp_token;
	}
}