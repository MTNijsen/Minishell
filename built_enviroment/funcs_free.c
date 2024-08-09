#include "../minishell.h"

void	free_array(char	**array)
{
	int	i;

	i = -1;
	while (array[++i] != NULL)
		free(array[i]);
	free(array);
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
