#include <stdio.h>
#include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>
# include <stdarg.h>

int main (void)
{
	char str[100];
	getcwd(str, 100);
	printf("%d\n", errno);
	perror("getcwd");

	chdir("src");
	printf("%d\n", errno);
	perror("chdir");
}