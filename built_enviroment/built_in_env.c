#include "../minishell.h"

void bi_env(t_data *data)
{
	int	i;

	i = 0;
	while(data->envp[i] != NULL)
		printf("%s\n", data->envp[i++]);
}
