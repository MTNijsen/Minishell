/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/14 21:08:33 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
/** 
* @brief The different enum types for the tokens
*
* @param TEXT: is everything that is text before reclassifying
* @param PIPE: (|)
* @param IN_REDIRECT: (>)
* @param OUT_REDIRECT: (<)
* @param APP_REDIRECT: (>>)
* @param HEREDOC: (<<)
* @param COMMAND: is a command
* @param FILES: is the in or out file
* @param STRING: is a string
*/
typedef enum e_type
{
	TEXT,
	PIPE,
	IN_REDIRECT,
	OUT_REDIRECT,
	APP_REDIRECT,
	HEREDOC,
	COMMAND,
	FILES,
	STRING
}			t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
}					t_token;

typedef struct s_redir
{
	t_type			type; // < << > >>
	char			*file; // test.txt, EOF
	struct s_redir	*next;
}					t_redir;

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
	t_redir			*redirs;
	int				hd_pipe[2];
	int				token_count;
	int				index;
	struct s_proc	*next;
}					t_proc;
/**
 * @brief	This is the giant struct with all of the data from the current prompt
 * 
 * @param	procs: linked list of all processes containing information.
 * @param	tokens: linked list of all tokens after tokenization in the lexer.
 * @param	envp: environment pointer.
 * @param	input: string of input from the user.
 */
typedef struct s_data
{
	t_proc	*procs;
	int		proc_count;
	t_token	*tokens;
	int		token_count;
	char	**envp;
	char	*input;
}			t_data;

#endif