#include "minishell.h"

int main(void)
{
	char	*buf;

	buf = getenv("PWD");
	if (buf)
	{
		printf("%s\n", buf);
		return (0);
	}
	buf = (char *)malloc(sizeof(char) * 4096);
	if (!buf)
		return (1);
	if (getcwd(buf, 4096) == NULL)
		return (free(buf), 1);
	printf("%s\n", buf);
	return (free(buf), 0);
}
