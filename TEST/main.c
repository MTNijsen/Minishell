#include "test.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <ctype.h>
# include <stdarg.h>


int	main(void)
{
	char *old = "Des\"tringis\'d\'i\"t";
	char *new;

	printf("OLD STRING: %s\n", old);
	new = handle_quotes(old);
	printf("NEW STRING: %s\n", new);
	
	return (0);
}