/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/09 16:18:07 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/24 17:12:03 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_dirs(char *output, char **array)
{
	char	*temp;
	int		i;

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
		if (!temp)
			return (NULL);
		output = temp;
		i++;
	}
	if (output[0] == '\0')
	{
		free(output);
		output = ft_strdup("/");
	}
	return (output);
}

/*returns absolute path to directory on success, 
exits on malloc failure and returns NULL when env PWD is not found */
char	*parse_dir(char *str, t_data *data)
{
	char	*output;
	char	*temp;
	char	**array;

	output = NULL;
	if (str[0] == '/')
		output = ft_strdup("");
	else
	{
		temp = return_pwd(data);
		if (!temp)
			return (NULL);
		output = ft_strdup(temp);
	}
	if (!output)
		clean_exit(data, MALLOC_ERROR);
	array = ft_split(str, '/');
	if (!array)
		clean_exit(data, MALLOC_ERROR);
	output = add_dirs(output, array);
	ft_free_arr(array);
	if (!output)
		clean_exit(data, MALLOC_ERROR);
	return (output);
}

char	*expand_path(t_data *data, char *arg)
{
	char	*cmd;
	char	*dir;
	char	*temp;

	dir = ft_substr(arg, 0, ft_strrchr(arg, '/') - arg);
	if (!dir)
		clean_exit(data, MALLOC_ERROR);
	temp = parse_dir(dir, data);
	free(dir);
	if (!temp)
		return (NULL);
	dir = temp;
	cmd = ft_substr(arg, ft_strrchr(arg, '/') - arg, ft_strlen(arg) - \
		(ft_strrchr(arg, '/') - arg));
	if (!cmd)
	{
		free(dir);
		clean_exit(data, MALLOC_ERROR);
	}
	temp = ft_strjoin(dir, cmd);
	free(dir);
	free(cmd);
	if (!temp)
		clean_exit(data, MALLOC_ERROR);
	return (temp);
}

char	*check_paths(t_data *data, char *arg)
{
	char	**path_locations;
	char	*temp;
	size_t	i;

	temp = return_env_val(data->envp, "PATH");
	if (temp == NULL)
		return (arg);
	path_locations = ft_split(temp, ':');
	if (!path_locations)
		clean_exit(data, MALLOC_ERROR);
	i = 0;
	while (path_locations[i] != NULL)
	{
		temp = ft_triappend(path_locations[i], "/", arg);
		if (access(temp, F_OK) == 0)
			return (ft_free_arr(path_locations), temp);
		free(temp);
		i++;
	}
	return (ft_free_arr(path_locations), arg);
}

int	get_path(t_data *data, t_proc *proc)
{
	char	*cmd;

	if (ft_strchr(proc->argv[0], '/'))
		cmd = expand_path(data, proc->cmd);
	else
		cmd = check_paths(data, proc->cmd);
	if (access(cmd, X_OK) == 0)
	{
		free(proc->cmd);
		proc->cmd = cmd;
		proc->argv[0] = cmd;
		return (0);
	}
	perror(proc->cmd);
	return (1);
}
