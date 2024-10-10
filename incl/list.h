/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/09 13:24:31 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"
# include "structs.h"

// TOKENS //
t_token	*create_token(t_type type, const char *value);
void	add_token(t_data *data, t_token *new);
void	free_tokens(t_token **tokens);
void	print_tokens(t_token *lst);
t_token	*last_token(t_token *lst);
int		count_tokens(t_data *data);

int		create_pipe_token(t_data *data, int i);
int		create_redir_token(t_data *data, char *input, int i);
int		create_right_redir(t_data *data, char *input, int i);
int		create_left_redir(t_data *data, char *input, int i);
int		create_text_token(t_data *data, char *input, int i);

// PROCS //
t_proc	*init_proc(void);
t_proc	*create_proc(t_token *token);
void	add_proc(t_data *data, t_proc *new);
void	add_redir(t_token **redirs, t_token *new);
void	free_procs(t_proc **procs);
void	print_procs(t_proc *lst);
t_proc	*last_proc(t_proc *lst);
int		get_procs(t_data *data);
int		count_tokens_proc(t_token *token);

// ENV //
bool	is_valid_env(char *env_var);
void	realloc_envp(t_data *data, size_t size);
int		modify_env_var(t_data *data, char *env_var);
void	remove_env_var(t_data *data, char *name);
char	*return_env_val(char **envp, char *name);
int		copy_array(char ***new_array, char **old_array);
char	*return_pwd(t_data *data);

#endif