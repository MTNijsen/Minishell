/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 15:48:19 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"
/** 
* @brief The different enum types for the tokens
*
* @param CMD is a command
* @param PIPE (|)
* @param IN_REDIRECT (>)
* @param OUT_REDIRECT (<)
* @param APP_REDIRECT (>>)
* @param HEREDOC (<<)
* @param FILE is the in or out file
* @param STRING is a string
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
	IN_FILE,
	OUT_FILE,
	APP_FILE,
	DELIMITER,
	STRING
}			t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
}					t_token;

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
	char			**args;
	char			**hd;
	char			**redir;
	int				token_count;
	int				index;
	struct s_proc	*next;
}					t_proc;

#endif