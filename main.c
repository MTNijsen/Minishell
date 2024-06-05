#include "executor.h"

int main(int argc, char *argv[], char *envp[])
{
	// t_output *first_node;
	// t_output *current_node;


	// first_node = (t_output *)malloc(sizeof(t_output));
	// current_node = first_node;
	// current_node->node = "cd";
	// current_node->type_node = MINI_BUILTIN;
	// // current_node->next_node = (t_output *)malloc(sizeof(t_output));
	// current_node = current_node->next_node
	int i = -1;
	while(envp[++i] != NULL)
	{
		printf("envp = %s\n", envp[i]);
	}
	// char buf[100];
	// getcwd(buf, 100);
	// printf("pwd = %s\n", buf);
	// executor(first_node, envp);
}