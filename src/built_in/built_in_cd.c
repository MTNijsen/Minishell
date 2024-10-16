/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_cd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:35 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 17:09:35 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	straight_cd(char **argv, t_data *data, char **pwd, char **temp)
{
	if (argv[1] == NULL || !ft_strncmp(argv[1], "--", 3))
	{
		*pwd = return_env_val(data->envp, "HOME");
		if ((*pwd) == NULL)
			write(2, "Error: HOME not set\n", 21);
	}
	else if (!ft_strncmp(argv[1], "-", 2))
	{
		*pwd = return_env_val(data->envp, "OLDPWD");
		if ((*pwd) == NULL)
			write(2, "Error: OLDPWD not set\n", 23);
	}
	else
	{
		*pwd = parse_dir(argv[1], data);
		if (*pwd == NULL)
			return (COMMON_ERROR);
		*temp = *pwd;
	}
	return (0);
}

int	bi_cd(char **argv, t_data *data)
{
	char	*pwd;
	char	*oldpwd;
	char	*temp;

	pwd = NULL;
	temp = NULL;
	if (straight_cd(argv, data, &pwd, &temp))
		return (COMMON_ERROR);
	oldpwd = return_pwd(data);
	if (oldpwd == NULL)
		return (COMMON_ERROR);
	if (chdir(pwd))
		return (perror(argv[1]), free(temp), 1);
	pwd = ft_strappend("PWD=", pwd);
	oldpwd = ft_strappend("OLDPWD=", oldpwd);
	free(temp);
	if (modify_env_var(data, pwd) || modify_env_var(data, oldpwd))
		clean_exit(data, MALLOC_ERROR);
	return (0);
}
