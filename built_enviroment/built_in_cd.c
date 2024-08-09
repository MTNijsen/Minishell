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

static char	*parse_cd(char *str, t_data *data)
{
	char *output;
	int	i;

	i = 0;
	if (str[0] == '/')
		output = ft_strdup("");
	else
		output = ft_strdup(return_pwd(data));
	if (!output)
		return(NULL);
	return (cd_add_dirs(str, output, i));
}

//still needs alot of work cleaning up and exit coding
int bi_cd(char **argv, t_data *data)
{
	char	*pwd;
	char	*oldpwd;
	char	*temp;

	temp = NULL;
	if (argv[1] == NULL || !ft_strncmp(argv[1], "--", 3))
		pwd = return_env_val(data->envp, "HOME");
	else if (!ft_strncmp(argv[1], "-", 2))
		pwd = return_env_val(data->envp, "OLDPWD");
	else
	{
		pwd = parse_cd(argv[0], data);
		temp = pwd;
	}
	oldpwd = return_pwd(data);
	if (!oldpwd)
		return (errno);
	if (chdir(pwd))
		return (errno);
	if (modify_env_var(data, ft_strappend("PWDPWD", pwd)) || \
		modify_env_var(data, ft_strappend("OLDPWD", oldpwd)))
	{
		free(temp);
		clean_exit(data, MALLOC_FAILURE);
	}
	return (0);
}
