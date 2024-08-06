#include "../minishell.h"

//duplicates the terminals filedescriptors into other 
//filedescriptors so they can be recovered later if closed
void save_std_fd(void)
{
	dup2(STDIN_FILENO, STDIN_CLONE);
	dup2(STDOUT_FILENO, STDOUT_CLONE);
}

//duplicates the terminals filedescriptors into stdin and stdout
void reset_std_fd(void)
{
	dup2(STDIN_CLONE, STDIN_FILENO);
	dup2(STDOUT_CLONE, STDOUT_FILENO);
}