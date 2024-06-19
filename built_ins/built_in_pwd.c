#include "minishell.h"

int bi_pwd(t_env *env_node)
{
	char	*buf;

	buf = return_env(env_node, "PWD");
	if (buf)
	{
		printf("%s\n", buf);
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * 4096);
	if (!buf)
		return (MALLOC_FAILURE);
	if (getcwd(buf, 4096) == NULL)
		return (free(buf), 1);
	printf("%s\n", buf);
	return (free(buf), 0);
}
