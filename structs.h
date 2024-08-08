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

typedef struct s_redir
{
	t_type	type; // < << > >>
	char	*file; // test.txt, EOF
	struct s_redir	*next;
}	t_redir;

/**
 * @brief	This struct will be a node in a list of processes. It's an organized
 * 			way to pass all command details to the executor. After tokenization 
 * 			by the lexer, the tokens are parsed into instances of t_procs, 
 * 			which are then processed by the executor to handle the command 
 * 			execution, including handling of arguments, heredocs, 
 * 			and redirections.
 * @param	cmd: first string in each process which is not a redirect or file.
 * @param	args: array of all cmd args.
 * @param	hd: array of all hd delimiters ignoring hd meta itself.
 * 				error if no string after hd meta
 * @param	redir: array of all < > >> in, out and truncate files, 
 * 			left in order as inputted. file after each meta character included.
 * 			error if no string after meta
 * @param	token_count: amount of tokens in process.
 * @param	index: index of which number proces this is. starting with 0.
 */

typedef struct s_proc
{
	char			*cmd;
	char			**argv;
	t_redir			*redir;
	int				hd_pipe[2];
	int				token_count;
	int				index;
	struct s_proc	*next;
}					t_proc;

#endif