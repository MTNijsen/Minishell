/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 19:02:24 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"
# include "structs.h"

// TOKENS //
t_token	*create_token(t_type type, const char *value);
void	add_token(t_token **head, t_token *new);
void	free_tokens(t_token **tokens);
void	print_tokens(t_token *lst);
t_token	*last_token(t_token *lst);
int		count_tokens(t_token **tokens);
int		create_pipe_token(t_token **head, int i);
int		create_redir_token(t_token **head, char *input, int i);
int		create_right_redir(t_token **head, char *input, int i);
int		create_left_redir(t_token **head, char *input, int i);
int		create_text_token(t_token **head, char *input, int i);
int		create_quotes_token(t_token **head, char *input, int i);
int		text_tokens(t_token **head, char *input, int i);

// PROCS //
t_proc	*init_proc(void);
void	add_proc(t_proc **head, t_proc *new);
void	free_procs(t_proc **procs);
void	print_procs(t_proc *lst);
t_proc	*last_proc(t_proc *lst);


#endif