/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 16:49:08 by lade-kon      ########   odam.nl         */
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
	STRING
}			t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
}					t_token;

#endif