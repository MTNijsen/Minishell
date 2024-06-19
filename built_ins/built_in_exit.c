#include "../minishell.h"

/*interesting quirk redirection can be done whilst still quiting but with a pipe it does nothing as then exit is given on fork*/
//print exit if not child process ????
int bi_exit(bool is_child)
{
	if (!is_child)
		printf("exit\n");
	exit (0);
}