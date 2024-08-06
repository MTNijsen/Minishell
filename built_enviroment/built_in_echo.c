#include "../minishell.h"

static int	is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

//works with write instead of printf as there isnt a \n at all times to flush the cache
int	bi_echo(const t_token *token)
{
	int		flags;
	t_token	*current_token;

	current_token = token->next;
	flags = 0;
	while (current_token != NULL && is_flag(current_token->value))
	{
		current_token = current_token->next;
		flags = 1;
	}
	while (current_token != NULL)
	{
		write(1, current_token->value, ft_strlen(current_token->value));
		current_token = current_token->next;
		if (current_token->value != NULL)
			write(1, " ", 1);
	}
	if (!flags)
		write(1, "\n", 1);
	return (0);
}
