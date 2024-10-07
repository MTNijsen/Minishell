/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/10/07 13:22:22 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "list.h"
# include "structs.h"
# include "errors.h"
# include <readline/readline.h>
# include <readline/history.h>

int		ft_lexer(t_data *data, char *input);
int		input_check(t_data *data);
bool	is_special(char input, const char *check);
void	ft_error(t_data *data, int flag);
t_data	*init_struct(char **env);
bool	is_redirect(t_token *token);
void	free_struct(t_data *data);
void	free_data(t_data *data);
void	print_data(t_data *data);


int		executor(t_data *data);
int		redirect(t_proc *proc);
int		heredoc(t_data *data);
int		get_path(t_data *data, t_proc* proc);

int		bi_cd(char **argv, t_data *data);
void	bi_echo(char **argv);
void	bi_env(t_data *data);
void	bi_exit(char **argv, t_data *data, bool pipe_present);
void	bi_export(char **argv, t_data *data);
int		bi_pwd(t_data *data);
void	bi_unset(char **argv, t_data *data);

int		pipeline(void);
void	wait_exit(int pid, int *exit_code);
void	clean_exit(t_data *data, int exit_status);
char	*ft_strappend(char const *s1, char const *s2);
char	*ft_triappend(char const *s1, char const *s2, char const *s3);
char	*ft_strchr_null(const char *str, int c);

//HANDLING QUOTES//
void	handle_quotes(t_data *data);


// filedescriptors for recovering stdin and stdout if overwritten
# define STDIN_CLONE 3
# define STDOUT_CLONE 4

//
# define ENV_VARIABLE_LENGTH 96

#endif