/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/08/28 10:43:57 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_data *data, t_token *token)
{
	char	*to_expand;
	t_token	*current;
	int		i;
	int		len;

	i = 0;
	current = token;
	if (ft_strcmp(current->value, "$") == 0)
	{
		to_expand = current->next->value;
		len = ft_strlen(current->next->value)
		if (current->next->value[0] == '\"')
		{
			to_expand = ft_substr(current->next->value, 0, len);
			// delete $ en text token en add expanded tokens.
		}
	}
}
