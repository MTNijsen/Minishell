#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <wait.h>
#include <error.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
	open("NO", X_OK);
	perror("NO");
}