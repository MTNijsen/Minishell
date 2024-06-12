/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/12 18:34:14 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

typedef struct s_output
{
	char			*node;
	int				type_node;
	struct s_output	*next;
}					t_output;

#define COMMAND 1
#define BUILTIN 2
#define FLAG 3
#define FILE 4
#define STRING 5
#define PIPE 6
#define REDIRECT 7
#define ENV_VARIABLE 8
#define LAST_EXIT 9
#define TYPE_NOT_FOUND 0

#endif