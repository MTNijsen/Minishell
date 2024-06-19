/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mnijsen <mnijsen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/28 14:11:13 by mnijsen       #+#    #+#                 */
/*   Updated: 2024/05/29 11:48:47 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libmt/libmt.h"

typedef struct s_pipex
{
	int	infile;
	int outfile;
	int proccess_count;
}	t_pipex;

int		open_file(char *argv, int i);

#define INVALIDFILE 0
#define WRONGCOUNT 1
#define PIPEBREAK 2
#define NOPATH 3
#define EXECFAIL 4
#define ALLOCFAIL 5

#endif
