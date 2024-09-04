/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 19:04:09 by lade-kon      ########   odam.nl         */
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
		len = ft_strlen(to_expand);
		if (to_expand[0] == '\"')
		{
			to_expand = ft_substr(to_expand, 1, (len - 2));
			// delete $ en text token en add expanded tokens.
		}
	}
}

int	main()
{
	t_token	*new;
	t_token	*new2;
	t_token	**head;

	head = NULL;
	new = create_token(STRING, "$");
	add_redir(head, new);
	new2 = create_token(STRING, "Hallo");
	add_redir(head, new2);


	return (0);
}