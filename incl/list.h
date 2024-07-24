/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/07/24 19:22:13 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"
# include "structs.h"

void		ft_add_node_back(t_token **lst, t_token *new);
void		ft_add_node_front(t_token **lst, t_token *new);
void		ft_clear_list(t_token **lst, void (*del)(void*));
void		ft_delone_node(t_token *lst, void (*del)(void*));
t_token	*ft_last_node(t_token *lst);
t_token	*ft_new_node(void *content);
void		ft_print_list(t_token *lst);
int			ft_size_list(t_token *lst);

t_token	make_parse_list(char **input);

#endif