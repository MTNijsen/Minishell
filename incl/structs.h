/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 18:00:55 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

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
}					t_token;

#endif