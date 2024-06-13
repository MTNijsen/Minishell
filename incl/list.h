/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 19:12:56 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/06/13 14:09:29 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "minishell.h"

void		ft_add_node_back(t_output **lst, t_output *new);
void		ft_add_node_front(t_output **lst, t_output *new);
void		ft_clear_list(t_output **lst, void (*del)(void*));
void		ft_delone_node(t_output *lst, void (*del)(void*));
t_output	*ft_last_node(t_output *lst);
t_output	*ft_new_node(void *content);
void		ft_print_list(t_output *lst);
int			ft_size_list(t_output *lst);

t_output	make_parse_list(char **input);

#endif