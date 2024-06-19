#include "../minishell.h"

int	bi_unset(t_env *env_node, char *name)
{
	return (remove_env(env_node, name));
}