/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 14:17:47 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "list.h"

typedef struct s_output
{
	t_token			token;
	struct s_output	*next;
}					t_output;

typedef struct s_token
{
	char			*value;
	t_type			type;
}					t_token;

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


t_token	*create_token(t_type type, const char *value);
void	free_token(t_token *token);


#endif