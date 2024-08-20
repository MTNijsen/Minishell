/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 16:09:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"
# include "structs.h"

// TOKENS //
t_token	*create_token(t_type type, const char *value);
void	add_token(t_data *data, t_token *new);
void	free_tokens(t_data *data);
void	print_tokens(t_token *lst);
t_token	*last_token(t_token *lst);
int		count_tokens(t_data *data);

int		create_pipe_token(t_data *data, int i);
int		create_redir_token(t_data *data, char *input, int i);
int		create_right_redir(t_data *data, char *input, int i);
int		create_left_redir(t_data *data, char *input, int i);
int		create_text_token(t_data *data, char *input, int i);
int		create_quotes_token(t_data *data, char *input, int i);
int		text_tokens(t_data *data, char *input, int i);

// PROCS //
t_proc	*init_proc(void);
t_proc	*create_proc(t_data *data, t_token *token, int proc);
void	add_proc(t_data *data, t_proc *new);
void	free_procs(t_proc **procs);
void	print_procs(t_proc *lst);
t_proc	*last_proc(t_proc *lst);
t_proc	*init_proc(void);
int		count_tokens_proc(t_token *token);

// REDIRS //
t_redir	*create_redir(t_type type, char *file);
void	add_redir(t_data *data, t_redir *new);
void	free_redirs(t_redir **redirs);


#endif