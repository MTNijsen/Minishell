#include "../minishell.h"

static int	is_flag(char *str)
{
	int	i;
	int output;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i] == 'n')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

//change input node to segment
//works with write instead of printf as there isnt a \n at all times to flush the cache
int	bi_echo(char **args, t_env *env_node)
{
	int		flags;
	char	*output;
	int		i;

	if (args == NULL || args[0] == NULL)
		return (1);
	flags = 0;
	i = 1;
	while (args[i] != NULL && is_flag(args[i]))
	{
		i++;
		flags = 1;
	}
	while (args[i] != NULL)
	{
		write(1, args[i], strlen(args[i]));
		if (args[++i] != NULL)
			write(1, " ", 1);
	}
	if (!flags)
		write(1, "\n", 1);
	return (0);
}

int main(int argc, char *argv[])
{
	bi_echo(argv, NULL);
}