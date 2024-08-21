/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/21 21:52:48 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "list.h"
# include "structs.h"
# include <readline/readline.h>
# include <readline/history.h>

int		ft_lexer(t_data *data);
int		input_check(t_data *data);
bool	is_special(char input, const char *check);
int		handle_quotes(char *input, int i);
void	reclassify_text_token(t_data *data, int flag);
void	ft_error(t_data *data, int flag);
t_data	*init_struct(void);
bool	is_redirect(t_token *token);
void	free_struct(t_data *data);

#endif