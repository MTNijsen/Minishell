/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/08 15:55:25 by lade-kon      #+#    #+#                 */
/*   Updated: 2024/09/01 16:33:59 by mnijsen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H
# include "minishell.h"

/*	This is a list of possible errors that can occur.
	1. Syntax error:
		-	missing quotes
		-	unmatched parentheses/brackets
	2. Command not found:
		-	typo in command
		-	random command that doesnt exist
		-	no command at all
		-	Executable Not in PATH: If my_custom_script.sh is not 
			in a directory listed in PATH, Bash will not be able to find it.
	3. File or Directory not found:
		-	Non-existent File or Directory
		-	Incorrect File Paths in Commands

*/

#define	MALLOC_ERROR -1
#define SYNTAX_ERROR 1
#define COMMAND_ERROR 2
#define FILE_ERROR 3 

#endif