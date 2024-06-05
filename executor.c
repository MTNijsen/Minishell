#include "executor.h"
#include "minishell.h"

char *executor(t_output *node, char *envp[])
{
	printf("%s, %i", node->node, node->type_node);
	if (node->type_node = MINI_COMMAND)
		return command(node, envp);
	else if (node->type_node = MINI_BUILTIN)
		return builtin(node, envp);
	else if (node->type_node = MINI_FLAG)
		return flag(node, envp);
	else if (node->type_node = MINI_FILE)
		return file(node, envp);
	else if (node->type_node = MINI_STRING)
		return string(node, envp);
	else if (node->type_node = MINI_PIPE)
		return mini_pipe(node, envp);
	else if (node->type_node = MINI_REDIRECT)
		return redirect(node, envp);
	else if (node->type_node = MINI_ENV_VARIABLE)
		return env_variable(node, envp);
	else if (node->type_node = MINI_LAST_EXIT)
		return last_exit(node, envp);
	return (NULL);
}