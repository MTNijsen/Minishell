#include "../minishell.h"

t_token *redirect_in(t_token *token, int *exit_code)
{
	int	fd;
	fd = open(token->next->value, O_RDONLY);
	if (!fd)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 0);
	close(fd);
	return (token->next->next);
}

t_token *redirect_out(t_token *token, int *exit_code)
{
	int	fd;
	fd = open(token->next->value, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (token->next->next);
}

t_token *redirect_out_append(t_token *token, int *exit_code)
{
	int	fd;

	fd = open(token->next->value, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (!fd)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		*exit_code = errno;
		return (NULL);
	}
	dup2(fd, 1);
	close(fd);
	return (token->next->next);
}

int	redirect_later(t_token *first_token, t_heredoc *h_doc, int h_index, int *exit_code)
{
	t_token *token;
	t_token *temp_token;

	token = first_token->next;
	temp_token = first_token;
	while (token != NULL)
	{
		if (token->type >= IN_REDIRECT)
		{
			if (token->type == IN_REDIRECT)
				token = redirect_in(token, exit_code);
			else if (token->type == OUT_REDIRECT)
				token = redirect_out(token, exit_code);
			else if (token->type == APP_REDIRECT)
				token = redirect_out_append(token, exit_code);
			else if (token->type == HEREDOC)
				token = heredoc(token, h_doc, h_index, exit_code);
			if (*exit_code != 0)
			{
				free_tokens(temp_token);
				return (*exit_code);
			}
			temp_token->next = token;
		}
		else
		{
			temp_token = token;
			token = token->next;
		}
	}
	return (0);
}

//steps through t_token list till next PIPE and handles any redirections found
t_token	*redirect(t_token *first_token, t_heredoc *h_doc, int h_index, int *exit_code)
{
	t_token *temp_token;

	while (first_token != NULL && first_token->type >= IN_REDIRECT)
	{
		temp_token = first_token;
		if (first_token->type == IN_REDIRECT)
			first_token = redirect_in(first_token, exit_code);
		else if (first_token->type == OUT_REDIRECT)
			first_token = redirect_out(first_token, exit_code);
		else if (first_token->type == APP_REDIRECT)
			first_token = redirect_out_append(first_token, exit_code);
		else if (first_token->type == HEREDOC)
			first_token = heredoc(first_token, h_doc, h_index, exit_code);
		if (*exit_code != 0)
		{
			free_tokens(temp_token);
			return (NULL);
		}
		free_token(temp_token->next);
		free_token(temp_token);
	}
	redirect_later(first_token, h_doc, h_index, exit_code);
	if (*exit_code != 0)
	{
		free_tokens(first_token);
		return (NULL);
	}
	return (first_token);
}
