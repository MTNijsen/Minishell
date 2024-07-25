//PROTECT ALWAYS EXPECT NULL
#include "../minishell.h"

//perhaps check access rights first before chdir to give more specific error messages can also be accomplished with errno
//cd gets ".." not "." or "-"
//needs to handle them / per /

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

static char	*cd_parse(char *str, t_env *env_node)
{
	char *output;
	int	i;

	i = 0;
	if (str[0] == '/')
		output = ft_strdup("");
	else
		output = ft_strdup(return_pwd(env_node));
	if (!output)
		return(NULL);
	return (cd_add_dirs(str, output, i));
}
//change to take nodes not array
int bi_cd(const t_token *token, t_env *env_node)
{
	char	*local_dir;
	char	*temp;
	t_token	*current_token;

	if (token == NULL || env_node == NULL)
		return (1); //what exit code?
	current_token = token->next;
	if (current_token->value == NULL || !ft_strncmp(current_token->value, "--", 3))
	{
		temp = return_env(env_node, "HOME");
		if (!temp)
		{
			printf("$HOME has been unset, naughty naughty.");
			return (1); //what exit code?
		}	
		local_dir = ft_strdup(temp);
	}
	else if (!ft_strncmp(current_token->value, "-", 2))
	{
		temp = return_env(env_node, "OLDPWD");
		if (!temp)
		{
			printf("$OLDPWD has been unset, naughty naughty.");
			return (1); //what exit code?
		}	
		local_dir = ft_strdup(temp);
	}
	else
		local_dir = cd_parse(current_token->value, env_node);
	if (local_dir == NULL)
		return (MALLOC_FAILURE);
	temp = return_pwd(env_node);
	if (temp == NULL)
		return (free(local_dir), MALLOC_FAILURE);
	temp = ft_strdup(temp); //ensures its on the heap for when we change the OLDPWD
	if (temp == NULL)
		return (free(local_dir), MALLOC_FAILURE);
	if (chdir(local_dir))
	{
		printf("%s, does not exist or you do not have access\n", local_dir);
		return (free(local_dir), free(temp), 1); //what exit code?
	}
	if (modify_env(env_node, "OLDPWD", temp, 0))
		return (free(local_dir), free(temp), MALLOC_FAILURE);
	if (modify_env(env_node, "PWD", local_dir, 0))
		return (free(local_dir), MALLOC_FAILURE);
	return (0);
}
//maybe make a function that is return env and puts it on the heap
//~ does not need to be dealt with with testing directly from terminal, is it the same for our program? or does ~ need to be expanded into HOME probably in parsing step allong with env variables