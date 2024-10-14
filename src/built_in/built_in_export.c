/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   built_in_export.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 16:51:24 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/10/14 14:05:33 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	export_display(char **envp)
{
	int		i;
	char	*env_val;
	int		eq_index;

	i = 0;
	while (envp[i] != NULL)
	{
		env_val = ft_strchr(envp[i], '=');
		if (!env_val)
		{
			printf("-x declare %s\n", envp[i]);
		}
		else
		{
			eq_index = env_val - envp[i];
			write(1, "-x declare ", 11);
			write(1, envp[i], eq_index);
			if (envp[i][eq_index +1] != '\0')
			{
				write(1, "=\"", 2);
				write(1, &envp[i][eq_index +1], ft_strlen(&envp[i][eq_index +1]));
				write(1, "\"", 1);
			}
			write(1, "\n", 1);
		}
		i++;
	}
}

static void	add_export(char **argv, t_data *data)
{
	int		i;
	char	*temp;

	i = 1;
	while (argv[i] != NULL)
	{
		printf("argv[i]= %s\n", argv[i]);
		temp = ft_strdup(argv[i]);
		if (modify_env_var(data, temp))
			free(temp);
		i++;
	}
}

void	bi_export(char **argv, t_data *data)
{
	if (argv[1] == NULL)
		export_display(data->envp);
	else
		add_export(argv, data);
}
