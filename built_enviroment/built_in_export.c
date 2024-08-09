#include "../minishell.h"

//bash displays in a sorted list but not needed
//all our variables in t_env are export variables thus its the same as env outside of format
static void export_display(char **envp)
{
	int	i;
	int eq_index;

	i = 0;
	while(envp[i] != NULL)
	{
		eq_index = strchr(envp[i], '=') -  envp[i];
		write(1, envp[i], eq_index);
		if (envp[i][eq_index +1] != '\0')
		{
			write(1, "=\"", 2);
			write(1, &envp[i][eq_index +1], 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

static void add_export(char **argv, t_data *data)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (modify_env_var(data, argv[i]))
			clean_exit(data, MALLOC_FAILURE);
		i++;
	}
}

void bi_export(char **argv, t_data *data)
{
	if (argv[1] == NULL)
		export_display(data->envp);
	else
		add_export(argv, data);
}
