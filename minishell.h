#ifndef MINISHELL
#define MINISHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "built_enviroment/libft.h"
#include <linux/limits.h>

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
}	t_env;

typedef struct s_heredoc
{
	int					pipe_ids[2];
	unsigned int		index;//maybe not needed if you just move thru it as you encounter heredocs during the creating of pipes otherwise anytime you encounter a heredoc you need to check how many heredocs there were before hand
	struct s_heredoc	*next_node;
}	t_heredoc;

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

t_env *array_to_list(char **envp);
void	free_env(t_env	*node);
char **list_to_array(t_env *node);
int	modify_env(t_env *node, char *name, char *content, bool heap);
int	remove_env(t_env *node, char *name);
char *return_env(t_env *node, char *name);

int bi_cd(char **args, t_env *env_node);
int	bi_echo(char **args);
int bi_env(t_env *env_node);
int bi_exit(bool is_child);
int bi_export(char **args, t_env *env_node);
int	split_env(char *str, char **output1, char **output2);
int bi_pwd(t_env *env_node);
int	bi_unset(char **name, t_env *env_node);
t_env *creat_env(char *name, char *content);
char *return_pwd(t_env *env_node);
int pipeline(void);



/*define common return codes mostly so malloc failure shuts the program down and isnt treated like other error codes like syntax error*/
#define MALLOC_FAILURE -1
#define SUCCES 0
#define COMMON_FAILURE 1

#define LOCAL 0
#define EXPORT 1

#define ENV_VARIABLE_LENGTH 96

#endif