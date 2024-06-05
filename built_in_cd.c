//PROTECT ALWAYS EXPECT NULL
#include "minishell.h"

//maybe needs to change envp???
int main(int argc, char *argv[], char *envp[])
{
	if (argc == 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == '\0')
		{
			if (chdir(getenv("OLDPWD")))
			{
				printf("Directory does not exist\n");
				return (1);
			}
		}
		else if (chdir(argv[1]))
		{
			printf("Directory does not exist\n");
			return (1);
		}
		char buf[100];
		printf("Directory became = %s\n", getcwd(buf, 100));
		return (0);
		(void)envp;
	}
	return (1);
}