#include "../minishell.h"

//unsets all token.values found except first which is the command
void	bi_unset(char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		remove_env_var(data, argv[i]);
		i++;
	}
}
