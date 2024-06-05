#include "minishell.h"

/*does not need to take arguments like in bash, what if no envp*/
int main(int argc, char *argv[], char *envp[])
{
	int	i;
	char *output;

	if (!envp)
		return (1);
	(void)argc;
	(void)argv;
	i = -1;
	while(envp[++i])
		printf("%s\n", envp[i]);
	return (0);
}
