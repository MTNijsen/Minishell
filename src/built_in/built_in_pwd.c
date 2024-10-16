/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_pwd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:20 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 17:06:15 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <linux/limits.h>

char	*return_pwd(t_data *data)
{
	char	*buf;
	char	buf_m[PATH_MAX];

	buf = return_env_val(data->envp, "PWD");
	if (buf)
		return (buf);
	if (getcwd(buf_m, PATH_MAX) == NULL)
	{
		write(STDERR_FILENO, SASS, ft_strlen(SASS));
		return (NULL);
	}
	buf = ft_strappend("PWD=", buf_m);
	if (!buf)
		clean_exit (data, MALLOC_ERROR);
	modify_env_var(data, buf);
	return (return_env_val(data->envp, "PWD"));
}

int	bi_pwd(t_data *data)
{
	char	*buf;

	buf = return_pwd(data);
	if (!buf)
		return (COMMON_ERROR);
	printf("%s\n", buf);
	return (0);
}
