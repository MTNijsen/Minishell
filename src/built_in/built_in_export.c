/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_export.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:24 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/16 18:10:01 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_display(char **envp)
{
	int		i;
	char	*env_val;
	int		ei;

	i = 0;
	while (envp[i] != NULL)
	{
		env_val = ft_strchr(envp[i], '=');
		if (!env_val)
			printf("-x declare %s\n", envp[i]);
		else
		{
			ei = env_val - envp[i];
			write(1, "-x declare ", 11);
			write(1, envp[i], ei);
			if (envp[i][ei +1] != '\0')
			{
				write(1, "=\"", 2);
				write(1, &envp[i][ei +1], ft_strlen(&envp[i][ei +1]));
				write(1, "\"", 1);
			}
			write(1, "\n", 1);
		}
		i++;
	}
}

static int	add_export(char **argv, t_data *data)
{
	int		i;
	char	*temp;

	i = 1;
	while (argv[i] != NULL)
	{
		temp = ft_strdup(argv[i]);
		if (modify_env_var(data, temp))
		{
			printf("export: %s: not a valid identifier\n", temp);
			free(temp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	bi_export(char **argv, t_data *data)
{
	if (argv[1] == NULL)
		return (export_display(data->envp), 0);
	else
		return (add_export(argv, data));
}
