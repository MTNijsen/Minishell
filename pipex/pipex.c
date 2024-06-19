/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 14:10:38 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/06/07 16:24:01 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//also usefull for command
static char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/"); //make a join three just for it to be cleaner ?
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_array(path);
	return (0);
}

static void	execute(char *argv, char **envp)
{
	char	**cmd;
	int 	i;
	char	*path;
	
	i = -1;
	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		exit(printf(ALLOCFAIL)); //needs changing to return error
	}
	path = find_path(cmd[0], envp);
	if (!path)	
	{
		free_array(cmd);
		exit(printf(NOPATH));
	}
	if (execve(path, cmd, envp) == -1)
		exit(printf(EXECFAIL));
}

static void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(printf(PIPEBREAK));
	pid = fork();
	if (pid == -1)
		exit(printf(PIPEBREAK));
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.proccess_count = 2;
	pipex.outfile = open_file(argv[argc - 1], 1);
	pipex.infile = open_file(argv[1], 2);
	dup2(pipex.infile, STDIN_FILENO);
	while (pipex.proccess_count < argc - 2)
		child_process(argv[pipex.proccess_count++], envp);
	dup2(pipex.infile, STDOUT_FILENO);
	execute(argv[argc - 2], envp);
	exit(printf(WRONGCOUNT));
}
