/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_procs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:45:19 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/05 21:25:48 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_procs(t_data *data)
{
	t_token	*current_token;
	t_proc	*new_proc;
	t_count	*counter;

	counter = (t_count *)malloc(sizeof(t_count));
	ft_bzero(counter, sizeof(t_count));
	current_token = data->tokens;
	while (current_token)
	{
		new_proc = create_proc(current_token, counter);
		while (current_token->type != PIPE)
			current_token = current_token->next;
		if (current_token->type == PIPE)
		{
			add_proc(data, new_proc);
			current_token = current_token->next;
			counter->proc_c++;
		}
	}
	data->proc_count = counter->proc_c;
	return (0);
}
