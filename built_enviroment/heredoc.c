#include "../minishell.h"

t_token *heredoc(t_token *token, t_heredoc *h_node, unsigned int index, int *exit_code)
{
	while (h_node != NULL && h_node->index != index)
		h_node = h_node->next_node;
	if (h_node == NULL)
	{
		*exit_code = 1;
		return (NULL);
	}
	dup2(h_node->pipe_ids[0], 0);
	close(h_node->pipe_ids[0]);
	return (token->next->next);
}
// int heredoc_read(t_token *token, t_heredoc *last_node) //FIX
// {
// 	t_heredoc	*h_node;
// 	char		*buf;
// 	int			pid;
// 	static	int	index = 0;
	
// 	h_node = (t_heredoc *)malloc(sizeof(t_heredoc));
// 	if (!h_node)
// 		return (-1);
// 	h_node->next_node = NULL;
// 	h_node->index = index++;
// 	if (last_node)
// 		last_node->next_node = h_node;
// 	last_node = h_node;
// 	if (pipe(h_node->pipe_ids) == -1)
// 		return (-1);
// 	pid = fork();
// 	if (pid == -1)
// 		return (-1);
// 	if (pid)
// 	{
// 		close(h_node->pipe_ids[1]);
// 		return (pid);
// 	}
// 	while (get_next_line(buf))//make a simplified get_next_line that reads a static size per time
// 	{
// 		if (ft_strncmp(buf, node->next_node->node, ft_strlen(node->next_node->node)) == 0)
// 			exit(EXIT_SUCCESS);
// 		write(h_node->pipe_ids[1], buf, ft_strlen(buf));
// 		free(buf);
// 	}
// 	exit(EXIT_FAILURE);
// }
