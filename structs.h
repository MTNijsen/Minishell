#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
/** 
* @brief The different enum types for the tokens
*
* @param TEXT is a string
* @param PIPE (|)
* @param IN_REDIRECT (>)
* @param OUT_REDIRECT (<)
* @param APP_REDIRECT (>>)
* @param HEREDOC (<<)
*/
typedef enum e_type
{
	TEXT,
	PIPE,
	IN_REDIRECT,
	OUT_REDIRECT,
	APP_REDIRECT,
	HEREDOC
}			t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
}					t_token; // cat -e

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_heredoc
{
	int					pipe_ids[2];
	unsigned int		index;//based on section
	struct s_heredoc	*next;
}	t_heredoc;

typedef struct s_exec
{
	t_heredoc	*h_doc;
	int			index;
	bool		pipe_present;
}	t_exec;

#endif