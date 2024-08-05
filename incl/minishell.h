/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/05 17:00:07 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "list.h"
# include "structs.h"
# include <readline/readline.h>
# include <readline/history.h>

bool	ft_lexer(t_token **head, char *input);
bool	input_check(t_token **token_lst);
int		create_word_token(t_token **head, char *input, int i);
int		create_quotes_token(t_token **head, char *input, int i);
int		create_text_token(t_token **head, char *input, int i);
int		create_pipe_token(t_token **head, int i);
int		create_redir_token(t_token **head, char *input, int i);
int		create_right_redir(t_token **head, char *input, int i);
int		create_left_redir(t_token **head, char *input, int i);
bool	ft_isspecial(char input, const char *check);
int		handle_quotes(char *input, int i);
void	reclassify_text_token(t_token **head);

#endif