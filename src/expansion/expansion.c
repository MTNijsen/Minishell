/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/12 13:22:05 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

	// char	*to_expand;
	// int		i;
	// int		len;

	// if (ft_strcmp(current->next->value, "$") == 0)
	// 	to_delete = current->next;

	// to_expand = current->next->value;
	// len = ft_strlen(to_expand);
	// if (to_expand[0] == '\"')
	// {
	// 	to_expand = ft_substr(to_expand, 1, (len - 2));
	// 	printf("%s\n", to_expand);
	// 	// delete $ en text token en add expanded tokens.
	// }


void	delete_token(t_token **head, t_token *to_delete)
{
	t_token	*current;
	t_token *temp;
	if (*head == to_delete)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp->value);
		free(temp);
	}
	current = *head;
	while (current != NULL && current->next != to_delete)
		current = current->next;
	if (current != NULL && current->next == to_delete)
	{
		current->next = to_delete->next;
		free(to_delete->value);
		free(to_delete);
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