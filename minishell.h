#ifndef MINISHELL
#define MINISHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_output
{
	char			*node;
	int				type_node;
	struct s_output	*next_node;
}	t_output;
//also include env variables
//might aswell also include envp
#define MINI_COMMAND 1
#define MINI_BUILTIN 2
#define MINI_FLAG 3
#define MINI_FILE 4
#define MINI_STRING 5
#define MINI_PIPE 6
#define MINI_REDIRECT 7
#define MINI_ENV_VARIABLE 8
#define MINI_LAST_EXIT 9
#define MINI_TYPE_NOT_FOUND 0

char *pwd(void);
char *export(char *envp[]);
#endif