/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/01 19:03:46 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"
# include "structs.h"

t_token	*create_token(t_type type, const char *value);
void	add_token(t_token **head, t_token *new);
void	free_tokens(t_token **tokens);
void	print_tokens(t_token *lst);
t_token	*last_token(t_token *lst);

#endif