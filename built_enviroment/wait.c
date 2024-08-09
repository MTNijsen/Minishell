#include "../minishell.h"

void wait_exit(int pid, int *exit_code)
{
	if (pid != -1 && waitpid(pid, exit_code, 0) != -1)
	{
		if  (WIFEXITED(*exit_code))
			*exit_code = WEXITSTATUS(*exit_code);
		else
			*exit_code = WTERMSIG(*exit_code);
	}
}

void clean_exit(t_data *data, int exit_status)
{
	(void)data;
	exit(exit_status);
}