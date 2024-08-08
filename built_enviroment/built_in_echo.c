#include "../minishell.h"

static int	is_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

//works with write instead of printf as there isnt a \n at all times to flush the cache
int	bi_echo(const char **argv)
{
	int		flags;
	int		i;

	i = 1;
	flags = 0;
	while (argv[i] != NULL && is_flag(argv[i]))
	{
		flags = 1;
		i++;
	}
	while (argv[i] != NULL)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		if (argv[i] != NULL)
			write(1, " ", 1);
	}
	if (!flags)
		write(1, "\n", 1);
	return (0);
}
