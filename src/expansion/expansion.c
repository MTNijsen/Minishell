/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/04 19:24:52 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand(t_token *token)
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
			printf("%s\n", to_expand);
			// delete $ en text token en add expanded tokens.
		}
	}
}

int	main()
{
	t_token	*new;
	t_token	*new2;
	t_token	**head;

	head = (t_token **)malloc(sizeof(t_token));
	printf("start list\n");
	new = create_token(STRING, "$");
	add_redir(head, new);
	printf("token added\n");
	new2 = create_token(STRING, "\"Hallo > dit is < een redirect\"");
	add_redir(head, new2);
	printf("list made\n");
	printf("%s\n", new2->value);
	expand(*head);

	return (0);
}