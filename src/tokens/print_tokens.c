/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_tokens.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/25 18:08:49 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 19:29:57 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *lst)
{
	while (lst != NULL)
	{
		printf("TYPE: [%d]	VALUE: [%s]\n", lst->type, lst->value);
		lst = lst->next;
	}
}
