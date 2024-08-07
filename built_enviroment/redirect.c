#include "../minishell.h"

t_token *redirect_in(t_token *token, int *exit_code)
{
	int	fd;
	t_token *temp;

	fd = open(token->next->value, O_RDONLY);
	if (!fd)
	{
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 0);
	close(fd);
	return (token->next->next);
	temp = token->next->next;
	free_token(token->next);
	free_token(token);
	return (temp);
}

t_token *redirect_out(t_token *token, int *exit_code)
{
	int	fd;
	t_token *temp;

	fd = open(token->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
	{
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (token->next->next);
	temp = token->next->next;
	free_token(token->next);
	free_token(token);
	return (temp);
}

t_token *redirect_out_append(t_token *token, int *exit_code)
{
	int	fd;
	t_token *temp;

	fd = open(token->next->value, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (!fd)
	{
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (token->next->next);
	temp = token->next->next;
	free_token(token->next);
	free_token(token);
	return (temp);
}

t_token	*redirect_ifs(t_token *token, t_heredoc *h_doc, int index, int *exit_code)
{
	if (token->type == IN_REDIRECT)
		return (redirect_in(token, exit_code));
	else if (token->type == OUT_REDIRECT)
		return (redirect_out(token, exit_code));
	else if (token->type == APP_REDIRECT)
		return (redirect_out_append(token, exit_code));
	else if (token->type == HEREDOC)
		return (heredoc_receive(token, h_doc, index, exit_code));
}

//steps through t_token list till next PIPE and handles any redirections found
//exit code should be checked and first_token needs to be freed if it breaks
t_token	*redirect(t_token *first_token, t_heredoc *h_doc, int index, int *exit_code)
{
	t_token *temp_token;
	t_token *token;

	while (first_token != NULL && first_token->type >= IN_REDIRECT)
	{
		first_token = redirect_ifs(first_token, h_doc, index, exit_code);
		if (*exit_code != 0)
			return (first_token);
	}
	token = first_token->next;
	temp_token = first_token;
	while (token != NULL)
	{
		if (token->type >= IN_REDIRECT)
		{
			token = redirect_ifs(token, h_doc, index, exit_code);
			if (*exit_code != 0)
				return (first_token);
			temp_token->next = token;
		}
		else
		{
			temp_token = token;
			token = token->next;
		}
	}	
	return (first_token);
}
