#include "../minishell.h"

//CLEAN UPPPPP!!!!
void bi_exit(char **argv, t_data *data, bool pipe_present)
{
	if (!pipe_present)
		printf("exit\n");
	clean_exit(data, ft_atoi(argv[1]));
}