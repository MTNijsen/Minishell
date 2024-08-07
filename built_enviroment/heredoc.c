#include "../minishell.h"

t_token *heredoc_receive(t_token *token, t_heredoc *h_doc, unsigned int index, int *exit_code)
{
	t_token *temp;

	while (h_doc != NULL && h_doc->index != index)
		h_doc = h_doc->next;
	if (h_doc == NULL)
	{
		*exit_code = 1;
		return (NULL);
	}
	dup2(h_doc->pipe_ids[0], 0);
	close(h_doc->pipe_ids[0]);
	temp = token->next->next;
	free_token(token->next);
	free_token(token);
	return (temp);
}

static t_heredoc *heredoc_init(t_heredoc **h_doc_start, unsigned int index, int *exit_code)
{
	t_heredoc *h_doc;
	
	if (*h_doc_start)
	{
		h_doc = *h_doc_start;
		while (h_doc->next && h_doc->index != index)
			h_doc = h_doc->next;
		if (h_doc->index != index)
		{
			h_doc->next = (t_heredoc *)malloc(sizeof(t_heredoc));
			h_doc = h_doc->next;
		}
	}
	else
	{
		h_doc = (t_heredoc *)malloc(sizeof(t_heredoc));
		*h_doc_start = h_doc;
	}
	if (h_doc == NULL)
		*exit_code = MALLOC_FAILURE;
	return (h_doc);
}

static int heredoc_pipe(t_heredoc *h_doc, int *exit_code)
{
	int pid;

	if (pipe(h_doc->pipe_ids) == -1)
	{
		*exit_code = errno;
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		*exit_code = errno;
		return (-1);
	}
	if (pid)
	{
		close(h_doc->pipe_ids[1]);
		return (pid);
	}
	return (0);
}

static int	heredoc_section(char *deliminator, t_heredoc **h_doc_start, unsigned int index, int *exit_code)
{
	int		temp;
	char	*buf;
	t_heredoc *h_doc;

	h_doc = heredoc_init(h_doc_start, index, exit_code);
	if (h_doc == NULL)
		return (-1); 
	h_doc->index = index;
	temp = heredoc_pipe(h_doc, exit_code);
	if (temp == -1)
		return (-1);
	else if (temp != 0)
		return (temp);
	buf = readline("heredoc> ");
	while (buf != NULL)
	{
		if (ft_strncmp(buf, deliminator, ft_strlen(deliminator)) == 0)
			exit(EXIT_SUCCESS);
		write(h_doc->pipe_ids[1], buf, ft_strlen(buf));
		write(h_doc->pipe_ids[1], "\n", 1);
		free(buf);
		buf = readline("heredoc> ");
	}
	exit(EXIT_FAILURE);
}

t_heredoc *heredoc_read(t_token *token, int *exit_code)
{
	int				pid;
	unsigned int	index;
	t_heredoc		*h_doc;
	
	index = 0;
	h_doc = NULL;
	while (token != NULL)
	{
		if (token->type == PIPE)
			++index;
		if (token->type == HEREDOC)
		{
			pid = heredoc_section(token->next->value, &h_doc, index, exit_code);
			wait_exit(pid, exit_code);
			if (*exit_code != 0)
				return (free_heredoc(h_doc), NULL);
		}
		token = token->next;
	}
	return (h_doc);
}
