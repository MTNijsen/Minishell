/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_path.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/09 16:18:07 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/10 14:37:50 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*add_dirs(char *output, char **array)
{
	char	*temp;
	int		i;
	
	i = 0;
	//deal with any entries that can occur any amount of times like .. or dir name
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

//deal with first entry like / . ~ or else
char	*parse_dir(char *str, t_data *data)
{
	char	*output;
	char	*temp;
	char	**array;

	output = NULL;
	if (str[0] == '/')
	{
		output = ft_strdup("");
		if (!output)
			clean_exit(data, MALLOC_ERROR);
	}
	else if (str[0] == '~')
	{
		temp = return_env_val(data->envp, "HOME");
		if (temp)
		{
			output = ft_strdup(temp);
			if (!output)
				clean_exit(data, MALLOC_ERROR);
		}
	}
	else
	{
		temp = return_pwd(data);
		if (temp)
		{
			output = ft_strdup(temp);
			if (!output)
				clean_exit(data, MALLOC_ERROR);
		}
	}
	if (!output)
		return (NULL);
	array = ft_split(str, '/');
	if (!array)
		return (free(output), NULL);
	output = add_dirs(output, array);
	return (ft_free_arr(array), output);
}

char *expand_path(t_data *data, char *arg)
{
	char	*cmd;
	char 	*dir;
	char	*temp;

	dir = ft_substr(arg, 0, ft_strrchr(arg, '/') - arg);
	if (!dir)
		clean_exit(data, MALLOC_ERROR);
	temp = parse_dir(dir, data);
	free(dir);
	if (!temp)
		clean_exit(data, MALLOC_ERROR);
	dir = temp;
	cmd = ft_substr(arg, ft_strrchr(arg, '/') - arg, ft_strlen(arg) - (ft_strrchr(arg, '/') - arg));//copies all that occures after the last /
	if (!cmd)
	{
		free(dir);
		clean_exit(data, MALLOC_ERROR);
	}
	temp = ft_strjoin(dir, cmd);
	if (!temp)
		clean_exit(data, MALLOC_ERROR);
	return (free(dir), free(cmd), temp);
}

char *check_paths(t_data *data, char *arg)
{
	char	**path_locations;
	char	*temp;
	size_t	i;

	path_locations = ft_split(return_env_val(data->envp, "PATH"), ':');
	if (!path_locations)
		return (NULL);
	i = 0;
	while (path_locations[i] != NULL)
	{
		temp = ft_triappend(path_locations[i], "/", arg);
		if (!access(temp, F_OK))
			return (ft_free_arr(path_locations), temp);
		free(temp);
		i++;
	}
	return (ft_free_arr(path_locations), NULL);
}

int	get_path(t_data *data, t_proc* proc)
{
	char	*cmd;
	
	if (ft_strchr(proc->argv[0], '/')) //if path provided aka there is a / in the string
		cmd = expand_path(data, proc->cmd);
	else //split path env and concatinate command after the paths and check access for existing not executing
		cmd = check_paths(data, proc->cmd);
	if (!access(cmd, X_OK))
	{
		free(proc->cmd);
		proc->cmd = cmd;
		proc->argv[0] = cmd;
		return (0);
	}
	printf("%s doesnt exist\n", cmd);
	return (1);
}