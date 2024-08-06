#include "minishell.h"

int main(void)
{

	int fd = open("/dev/stdout", O_WRONLY);
	printf("fd = %d\n", fd);
	write(fd, "hello\n", 6);
}