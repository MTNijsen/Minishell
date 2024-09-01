/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 15:03:57 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/01 16:32:36 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void wait_exit(int pid, int *exit_code)
{
	if (pid != -1 && waitpid(pid, exit_code, 0) != -1)
	{
		if  (WIFEXITED(*exit_code))
			*exit_code = WEXITSTATUS(*exit_code);
		else
			*exit_code = WTERMSIG(*exit_code);
	}
}

void clean_exit(t_data *data, int exit_status)
{
	t_proc *temp_proc;
	t_token *temp_redir;

	free_array(data->envp);
	free(data->input);
	temp_proc = data->procs;
	while (temp_proc)
	{
		free_array(temp_proc->argv);
		temp_redir = data->procs->redirs;
		while(temp_redir)
		{
			free(temp_redir->value);
			temp_redir = temp_redir->next;
			free(data->procs->redirs);
			data->procs->redirs = temp_redir;
		}
		temp_proc = temp_proc->next;
		free(data->procs);
		data->procs = temp_proc;
	}
	free(data);
	exit(exit_status);
}
