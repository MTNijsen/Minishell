#include "minishell.h"

int	redirect_in(t_output *node)
{
	int	fd;

	fd = open(node->next_node->node, O_RDONLY);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}

int	redirect_out(t_output *node)
{
	int	fd;

	fd = open(node->next_node->node, O_WRONLY | O_CREAT | O_TRUNC);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	redirect_out_append(t_output *node)
{
	int	fd;

	fd = open(node->next_node->node, O_WRONLY | O_CREAT | O_APPEND);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int heredoc_read(t_output *node, t_heredoc *last_node)
{
	t_heredoc	*h_node;
	char		*buf;
	int			pid;
	static	int	index = 0;
	
	h_node = (t_heredoc *)malloc(sizeof(t_heredoc));
	if (!h_node)
		return (-1);
	h_node->next_node = NULL;
	h_node->index = index++;
	if (last_node)
		last_node->next_node = h_node;
	last_node = h_node;
	if (pipe(h_node->pipe_ids) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid)
	{
		close(h_node->pipe_ids[1]);
		return (pid);
	}
	while (get_next_line(buf))//make a simplified get_next_line that reads a static size per time
	{
		if (ft_strncmp(buf, node->next_node->node, ft_strlen(node->next_node->node)) == 0)
			exit(EXIT_SUCCESS);
		write(h_node->pipe_ids[1], buf, ft_strlen(buf));
		free(buf);
	}
	exit(EXIT_FAILURE);
}

int	heredoc(t_heredoc *h_node, unsigned int index)
{
	while (h_node != NULL && h_node->index != index)
		h_node = h_node->next_node;
	if (h_node == NULL)
		return (-1);
	dup2(h_node->pipe_ids[0], 0);
	close(h_node->pipe_ids[0]);
	return (0);
}

int	redirect(t_output *node, int h_index)
{
	int	fd;

	if (!ft_strcmp(node->node, "<"))
		return (redirect_in(node));
	if (!ft_strcmp(node->node, ">"))
		return (redirect_out(node));
	if (ft_strcmp(node->node, ">>"))
		return (redirect_out_append(node));
	if (ft_strcmp(node->node, "<<"))
		return (heredoc(node, h_index));//somehow needs to track which heredoc node we need to grab,
	return (1);
}