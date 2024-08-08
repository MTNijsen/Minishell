/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/08 19:31:01 by lade-kon      ########   odam.nl         */
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
bool	ft_isspecial(char input, const char *check);
int		handle_quotes(char *input, int i);
int		reclassify_text_token(t_token **head, int flag);

#endif