#include "../minishell.h"

void	free_env(t_env	*node)
{
	t_env	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node->content);
		free(node->name);
		free(node);
		node = next;
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
		fprintf(stderr, "shit %s\n", token->value);
		temp_token = token->next;
		free(token->value);
		free(token);
		token = temp_token;
	}

}

void	free_heredoc(t_heredoc *node)
{
	t_heredoc	*next;

	while (node != NULL)
	{
		next = node->next;
		free(node);
		node = next;
	}
}