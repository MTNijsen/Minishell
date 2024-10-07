/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   expansion.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/12 12:31:35 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/18 13:39:02 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"




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
	while (current != NULL && current != to_delete)
		current = current->next;
	if (current == to_delete)
	{
		current->next = to_delete->next;
		free(to_delete->value);
		free(to_delete);
	}
}

void	expand(t_data *data)
{
	t_token *current;
	char	*to_expand;
	char	*p_to_exp;
	t_token	*to_delete;
	char	*env_val;
	int		len_exp;
	int		i;

	current = data->tokens;
	while (current != NULL)
	{
		if (current->value[0] == "$")
		{
			len_exp = ft_strlen(current->value) - 1;
			to_expand = ft_substr(current->value, 1, len_exp);
			env_val = return_env_val(data->envp, to_expand);
			delete_token(&data->tokens, current);


		}
		else if (current->value[0] == "\"")
		{
			p_to_exp = ft_strchr(current->value, '$');
			len_exp = ft_wordlen(&p_to_exp, ' ');
			to_expand = ft_substr(current->value, &p_to_exp, len_exp);
			env_val = return_env_val(data->envp, to_expand);
			
			delete_token(&data->tokens, current);
		}
	}
}

	// int		i;
	// int		len;


	// to_expand = current->next->value;
	// len = ft_strlen(to_expand);
	// if (to_expand[0] == '\"')
	// {
	// 	to_expand = ft_substr(to_expand, 1, (len - 2));
	// 	printf("%s\n", to_expand);
	// 	// delete $ en text token en add expanded tokens.
	// }