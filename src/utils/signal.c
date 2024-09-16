/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/16 14:28:45 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/09/16 19:08:27 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <signal.h>

static	void sig_int(int sig)
{
	write(1, "\n", 1);
	g_sign = sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	//needs to somehow interrupt readline so that it will set x in the main 
}

void	set_sig(t_sign status)
{
	if (status == S_INTERACTIVE)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_int);
	}	
	else if (status == S_HEREDOC)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_DFL);
	}
	else
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
	}
}
