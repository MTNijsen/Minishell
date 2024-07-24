/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 16:30:58 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

typedef enum e_type
{
	T_COMMAND,
	T_BUILTIN,
	T_FLAG,
	T_FILE,
	T_STRING,
	T_PIPE,
	T_REDIRECT,
	T_ENV_VARIABLE,
	T_LAST_EXIT,
	T_TYPE_NOT_FOUND,
	T_EOF,
	T_UNKNOWN
}	t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
}					t_token;

typedef struct s_output
{
	t_token			token;
	struct s_output	*next;
}					t_output;

#endif