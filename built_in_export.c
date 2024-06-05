#include "minishell.h"

/*neds to take inputs like in bash to set export variables */
int main(int argc, char *argv[], char *envp[])
{
	int	i;
	char **output;

	if (!envp)
		return (1);
	(void)argc;
	(void)argv;
	i = -1;
	output = sort_strs(envp); //try to make sort strs without allocating by swapping pointers
	while(output[++i])
		printf("declare -x %s\n", output[i]);
	return (0);
}
