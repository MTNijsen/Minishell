#include "minishell.h"

int	redirect_in(t_output *node, char *envp[])
{
	int	fd;

	fd = open(node->next_node->node, O_RDONLY);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 0);
	return (0);
}

int	redirect_out(t_output *node, char *envp[])
{
	int	fd;

	fd = open(node->next_node->node, O_WRONLY | O_CREAT | O_TRUNC);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 1);
	return (0);
}

int	redirect_out_append(t_output *node, char *envp[])
{
	int	fd;

	fd = open(node->next_node->node, O_WRONLY | O_CREAT | O_APPEND);
	if (!fd)
	{
		write(2, errno, ft_strlen(errno));
		return (1);
	}
	dup2(fd, 1);
	return (0);
}

//needs prev node as place to be piped into
//next node is the limiter
int heredoc(t_output *node, char *envp[])
{
//here doc input happens before redirect check, then the nth heredoc is writen into the std when the the heredoc sign is encountered perhaps in each of the seperate processes
// the only issue there is that if one heredoc fails or is cancelled all need to o nothing
}

int	redirect(t_output *node, char *envp[])
{
	int	fd;

	if (!ft_strcmp(node->node, "<"))
		return (redirect_in(node, envp));
	if (!ft_strcmp(node->node, ">"))
		return (redirect_out(node, envp));
	if (ft_strcmp(node->node, ">>"))
		return (redirect_out_append(node, envp));
	if (ft_strcmp(node->node, "<<"))
		return (heredoc(node, envp));
	return (1);
}