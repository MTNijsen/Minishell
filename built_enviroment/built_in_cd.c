//PROTECT ALWAYS EXPECT NULL
#include "../minishell.h"

static char	*cd_add_dirs(char *str, char *output, int i)
{
	char *temp;
	char **array;

	array = ft_split(str, '/');
	if (!array)
		return (NULL);
	while (array[i] != NULL)
	{
		if (!ft_strncmp(array[i], ".", 2))
			temp = ft_strdup(output);
		else if (!ft_strncmp(array[i], "..", 2))
			temp = ft_substr(output, 0, ft_strrchr(output, '/') - output); 
		else
			temp = ft_triappend(output, "/", array[i]);
		free(output);
		if(!temp)
			return (free_array(array), NULL);
		output = temp;
		i++;
	}
	return(free_array(array), output);
}

static char	*cd_parse(char *str, char **envp)
{
	char *output;
	int	i;

	i = 0;
	if (str[0] == '/')
		output = ft_strdup("");
	else
		output = ft_strdup(return_pwd(envp));
	if (!output)
		return(NULL);
	return (cd_add_dirs(str, output, i));
}

//does it actually work with this split off
static char *cd_(char *value, char **envp)
{
	char	*temp;

	if (value == NULL || !ft_strncmp(value, "--", 3))
	{
		temp = return_env(envp, "HOME");
		if (!temp)
			return (temp);
		temp = ft_strdup(temp);
	}
	else if (!ft_strncmp(value, "-", 2))
	{
		temp = return_env(envp, "OLDPWD");
		if (!temp)
			return (temp);
		temp = ft_strdup(temp);
	}
	else
		temp = cd_parse(value, envp);
	return (temp);
}

//still needs alot of work cleaning up and exit coding
int bi_cd(char **argv, char ***envp)
{
	char	*local_dir = NULL;
	char	*temp;

	local_dir = cd_(argv[0], envp);
	if (local_dir == NULL)
		return (MALLOC_FAILURE);
	temp = return_pwd(envp);
	if (temp == NULL)
		return (free(local_dir), MALLOC_FAILURE);
	temp = ft_strdup(temp); //ensures its on the heap for when we change the OLDPWD
	if (temp == NULL)
		return (free(local_dir), MALLOC_FAILURE);
	if (chdir(local_dir))
		return (free(local_dir), free(temp), errno);
	if (modify_env(envp, "OLDPWD", temp, 0))
		return (free(local_dir), free(temp), MALLOC_FAILURE);
	if (modify_env(envp, "PWD", local_dir, 0))
		return (free(local_dir), MALLOC_FAILURE);
	return (0);
}
