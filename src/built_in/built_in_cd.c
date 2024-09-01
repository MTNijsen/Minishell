/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_cd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:35 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 16:51:44 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

static char	*cd_add_dirs(char *str, char *output)
{
	char *temp;
	char **array;
	int	i;

	array = ft_split(str, '/');
	if (!array)
		return (NULL);
	i = 0;
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
	if (output[0] == '\0')
	{
		free(output);
		output = ft_strdup("/");
	}
	return(free_array(array), output);
}

static char	*parse_cd(char *str, t_data *data)
{
	char *output;

	if (str[0] == '/')
		output = ft_strdup("");
	else
		output = ft_strdup(return_pwd(data));
	if (!output)
		return(NULL);
	return (cd_add_dirs(str, output));
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
		pwd = parse_cd(argv[1], data);
		temp = pwd;
	}
	oldpwd = return_pwd(data);
	if (!oldpwd)
		return (errno);
	if (chdir(pwd))
		return (free(pwd), errno);
	pwd = ft_strappend("PWD=", pwd);
	oldpwd = ft_strappend("OLDPWD=", oldpwd);
	free(temp);
	if (modify_env_var(data, pwd) || \
		modify_env_var(data, oldpwd))
		clean_exit(data, MALLOC_ERROR);
	return (0);
}
