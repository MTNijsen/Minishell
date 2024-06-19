//PROTECT ALWAYS EXPECT NULL
#include "../minishell.h"

//perhaps check access rights first before chdir to give more specific error messages can also be accomplished with errno
//cd gets ".." not "." or "-"
int bi_cd(char **args, t_env *env_node)
{
	char	*local_dir;

	if (args == NULL || args[0] == NULL || env_node == NULL)
		return (1);
	if (args[1] == NULL || !ft_strncmp(args[1], "~", 2))
		local_dir = return_env(env_node, "ROOT");
	else if (!ft_strncmp(args[1], "-", 2))
		local_dir = return_env(env_node, "OLDPWD");
	else if (!ft_strncmp(args[1], ".", 2))
		local_dir = return_env(env_node, "PWD");
	else
		local_dir = args[1];
	if (chdir(local_dir))
	{
		printf("Unable to access directory\n");
		return (1);
	}
	modify_env(env_node, "OLDPWD", return_env(env_node, "PWD"), 0);
	modify_env(env_node, "PWD", ft_strdup(local_dir), 0);
	return (0);
}
