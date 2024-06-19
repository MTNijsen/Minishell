#include "executor.h"
#include "minishell.h"

int execute_section(t_output *first_node, char *envp[], bool is_child)
{
	t_output *node;

	node = first_node;
	while (node != NULL)
	{
		if (node->type_node == MINI_REDIRECT)
			redirect(node, envp);//check for fail
		node = node->next_node;
	}
	node = first_node;
	while (node != NULL && node->type_node == MINI_REDIRECT)
		node->next_node;
	if (node != NULL && node->type_node == MINI_BUILTIN)
		return (builtin(node, envp));
	else
		return (command(node, envp, is_child));//find path and if found execve
}

//attach to the front signal handling
// maybe hvve a static variable for $? stored here or one step previous that is updated with exit code
int executor(t_output *first_node, char *envp[])
{
	t_output	*node;
	t_output	*start_section;
	bool		pipe_present;
	int			pid;

	node = first_node;
	start_section = first_node;
	pipe_present = false;
	while (node != NULL)
	{
		if (node->type_node == MINI_PIPE)
		{
			pipe_present = true;
			//setup pipeline
			//fork??
			execute_section(start_section, envp, true);//check for fail
			start_section = node->next_node;
		}
		node = node->next_node;
	}
	if (pipe_present == true)
		pid = fork();
	execute_section(start_section, envp, pipe_present);
	wait();//waitpid till all kids are done if one returns error code return handle by killing other??
	return (0);
}



/*
go over nodes first seeing what is a pipe, if found go to check in that 
section for redirects which does it stuff file descriptors should now be sorted

then to the executing stage where command/builtin is run with everything left in that section being its argv (including flags)
*/