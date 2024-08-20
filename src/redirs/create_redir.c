/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_redir.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/15 14:19:15 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/15 14:25:14 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir	*create_redir(t_type type, char *file)
{
	t_redir	*redir;

	redir = (t_redir *)malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = type;
	redir->file = ft_strdup(file);
	return (redir);
}
