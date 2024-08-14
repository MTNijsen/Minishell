#include "../minishell.h"

//CLEAN UPPPPP!!!!
void bi_exit(char **argv, t_data *data, bool pipe_present)
{
	if (!pipe_present)
		printf("exit\n");
	if (argv[1] != NULL)
		clean_exit(data, ft_atoi(argv[1]));
	clean_exit(data, 0);
}