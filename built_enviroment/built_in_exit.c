#include "../minishell.h"

//CLEAN UPPPPP!!!!
int bi_exit(bool is_child)
{
	if (!is_child)
		printf("exit\n");
	exit (0);
}