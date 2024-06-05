#include "minishell.h"

/*interesting quirk redirection can be done whilst still quiting but with a pipe it does nothing as then exit is given on fork*/
int main()
{
	exit (0);
}