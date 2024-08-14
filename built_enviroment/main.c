
#include "../minishell.h"



int main (int argc, char **argv, char **envp)
{
	t_data *data;
	char **new_envp;
	char **new_argv;
	t_redir *redir_2;
	// char *export[] = {"export", NULL};
	if (argc < 2)
	{
		printf("DUMBASS I NEED ARGUMENTS\n");
		return (1);
	}
	data = ft_calloc(1, sizeof(t_data));
	new_envp = NULL;
	copy_array(&new_envp, envp);
	data->envp = new_envp; 
	data->procs = ft_calloc(1, sizeof(t_proc));
	copy_array(&new_argv, &argv[1]);
	data->procs->argv = new_argv;
	data->procs->cmd = new_argv[0];
	data->procs->index = 0;
	data->procs->next = NULL;
	data->procs->proc_count = 0;
	data->procs->redir = ft_calloc(1, sizeof(t_redir));
	data->procs->redir->file = ft_strdup("test");
	data->procs->redir->type = OUT_REDIRECT;
	redir_2 = ft_calloc(1, sizeof(t_redir));
	data->procs->redir->next = redir_2;
	redir_2->file = ft_strdup("read");
	redir_2->type = IN_REDIRECT;
	int exit_code = executor(data);
	(void)argc;
	(void)argv;
	free(data->procs);
	free_array(new_envp);
	free_array(new_argv);
	free(data);
	return (exit_code);
}