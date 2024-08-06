#include "../minishell.h"

int bi_pwd(const t_env *env_node)
{
	char	*buf;
	char	buf_m[PATH_MAX];

	buf = return_env(env_node, "PWD");
	if (buf)
	{
		printf("%s\n", buf);
		return (0);
	}
	if (getcwd(buf_m, PATH_MAX) == NULL)
		return (1); //what exit code?
	printf("%s\n", buf_m);
	buf = ft_strdup(buf_m);
	if (!buf)
		return (MALLOC_FAILURE);
	modify_env(env_node, "PWD", buf, 0);
	return (0);
}

//to get the current process working directory for use inside another function
char *return_pwd(const t_env *env_node)
{
	char	*buf;
	char	buf_m[PATH_MAX];

	buf = return_env(env_node, "PWD");
	if (buf)
		return (buf);
	if (getcwd(buf_m, PATH_MAX) == NULL)
		return (NULL);
	buf = ft_strdup(buf_m);
	if (!buf)
		return (NULL);
	add_env(env_node, "PWD", buf, 0);
	return (return_env(env_node, "PWD"));
}