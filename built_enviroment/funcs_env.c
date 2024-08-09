#include "../minishell.h"

bool	is_valid_env(char *env_var)
{
	int	i;

	i = 0;
	if (env_var == NULL)
		return (0);
	if (ft_isdigit(env_var[i]))
		return (false);
	while (env_var[i] != '0' && env_var[i] != '=')
	{
		if (!ft_isalnum(env_var[i]) && env_var[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

//increases the allocated space for strings in envp and copies over all enviroment variables
//only use to increase the size of the envp, use remove env_var for a single variable being removed
//and free_array for freeing the whole array
char **realloc_envp(char **envp, size_t size, size_t *old_size)
{
	size_t	i;
	char **output;

	i = 0;
	output = (char **)malloc(sizeof(char *) * size);
	if (output == NULL)
		return (NULL);
	while (i < size && i < *old_size)
	{
		output[i] = ft_strdup(envp[i]);
		if (output == NULL)
			return (free_array(output), NULL);
		i++;
	}
	while (i < size)
	{
		output[i] = NULL;
		i++;
	}
	*old_size = size;
	free_array(envp);
	return (output);
}

int		modify_env_var(t_data *data, char *env_var)
{
	size_t i;
	const size_t var_len = strchr(env_var, '=') - env_var;

	i = 0;
	if (!is_valid_env(env_var))
		return (1);
	while (data->envp[i] != NULL && ft_strncmp(data->envp[i], env_var, var_len +1))//loop thru till you see NAME=VALUE
		i++;
	if (data->envp[i] != NULL)
	{
		free(data->envp[i]);
		data->envp[i] = env_var;
		return (0);
	}
	if (i == data->env_count)
		data->envp = realloc_envp(data->envp, i +2, &data->env_count);
	if (data->envp == NULL)
		clean_exit(data, MALLOC_FAILURE);
	data->envp[i] = env_var;
	return (0);
}

//frees and removes one enviroment variable which matches name before the '='
//and moves enviroment variable that came afterwards forwards by one spot
void	remove_env_var(t_data *data, char *name)
{
	size_t	i;
	const size_t name_len = ft_strlen(name);

	i = 0;
	while (data->envp[i] != NULL && ft_strncmp(data->envp[i], name, name_len +1) != '=')//loop thru till you see NAME=VALUE
		i++;
	if (data->envp[i] != NULL)
	{
		free(data->envp[i]);
		while (data->envp[i +1] != NULL)
		{
			data->envp[i] = data->envp[i +1];
			i++;
		}
		data->envp[i] = data->envp[i +1];
	}
}

//returns a pointer to the character after the '=' 
//found inside of the enviroment variable list
char	*return_env_val(char **envp, char *name)
{
	size_t	i;
	const size_t name_len = ft_strlen(name);

	if (!is_valid_env(name))
		return (NULL);
	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], name, name_len +1) != '=' )
		i++;
	if (envp[i] != NULL)
		return (&envp[i][name_len +1]);
	return (NULL);
}
