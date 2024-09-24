/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_cd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:35 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 18:07:14 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <errno.h>

int	bi_cd(char **argv, t_data *data)
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
		pwd = parse_dir(argv[1], data);
		if (pwd == NULL)
			return (errno);
		temp = pwd;
	}
	oldpwd = return_pwd(data);
	if (oldpwd == NULL)
		return (errno);
	if (chdir(pwd))
		return (free(pwd), perror(pwd), errno);
	pwd = ft_strappend("PWD=", pwd);
	oldpwd = ft_strappend("OLDPWD=", oldpwd);
	free(temp);
	if (modify_env_var(data, pwd) || modify_env_var(data, oldpwd))
		clean_exit(data, MALLOC_ERROR);
	return (0);
}
