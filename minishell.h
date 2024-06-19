#ifndef MINISHELL
#define MINISHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include "libft/libft.h"

typedef struct s_output
{
	char			*node;
	int				type_node;
	struct s_output	*next_node;
}	t_output;

typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next_node;
	bool			export;
}	t_env;
//also include env variables
//might aswell also include envp
#define MINI_COMMAND 1 //is the first in a section so doesnt matter
#define MINI_BUILTIN 2 //is the first in a section so doesnt matter can replace if we make a is builtin func
#define MINI_FLAG 3 //does not matter
#define MINI_FILE 4 //does not matter
#define MINI_STRING 5 //does not matter
#define MINI_PIPE 6
#define MINI_REDIRECT 7
#define MINI_ENV_VARIABLE 8 //expand before execute
#define MINI_LAST_EXIT 9 //can be converted to a builtin
#define MINI_TYPE_NOT_FOUND 0

char *pwd(void);
char *export(char *envp[]);
int	modify_env(t_env *node, char *name, char *content, bool export);
void	free_env(t_env	*node);
int	remove_env(t_env *node, char *name);
char *return_env(t_env *node, char *name);
int	split_env(char *str, char **output1, char **output2);

/*define common return codes mostly so malloc failure shuts the program down and isnt treated like other error codes like syntax error*/
#define MALLOC_FAILURE -1
#define SUCCES 0
#define COMMON_FAILURE 1

#endif