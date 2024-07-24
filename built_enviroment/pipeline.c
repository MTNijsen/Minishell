#include "../minishell.h"

//creates a child process and sets up a pipe between the child process' stdout and the parent process' stdin
int pipeline(void)
{
	int pipe_ids[2];
	int	pid;

	if (pipe(pipe_ids))
		return (-1);
	pid = fork();
	if (pid == -1)
		return (close(pipe_ids[0]), close(pipe_ids[1]),-1);
	if (pid)
	{
		close(pipe_ids[0]);
		dup2(pipe_ids[1], STDOUT_FILENO);
		close(pipe_ids[1]);
		return (pid);
	}
	close(pipe_ids[1]);
	dup2(pipe_ids[0], STDIN_FILENO);
	close(pipe_ids[0]);
	return (pid);
}

// int main(int args, char *argv[])
// {
// 	int pid = pipeline();
// 	char buf[100];
// 	if (pid == -1)
// 		write(1, "SHIT\n", 5);
// 	else if (pid > 0)
// 	{
// 		write(1, "Hello", 6);
// 	}
// 	else
// 	{
// 		pid = pipeline();
// 		if (pid)
// 		{
// 			printf("second read = %zd\n", read(STDIN_FILENO, buf, 100));
// 			printf("%s", buf);
// 		}
// 		else 
// 		{
// 			printf("third read = %zd\n", read(STDIN_FILENO, buf, 100));
// 			printf("-- %s --\n", buf);
// 		}
// 	}
// }
