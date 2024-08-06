#include "../minishell.h"

//creates a child process and sets up a pipe between the child process' stdout and the parent process' stdin
int pipeline(void)
{
	int pipe_ids[2];
	int	pid;

	if (pipe(pipe_ids) == -1)
		return (errno);
	pid = fork();
	if (pid == -1)
		return (close(pipe_ids[0]), close(pipe_ids[1]), errno);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
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
