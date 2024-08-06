#ifndef MINISHELL
#define MINISHELL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "built_enviroment/libft.h"
#include "structs.h"
#include <linux/limits.h>
#include <string.h>
#include <signal.h>



t_env *array_to_list(char **envp);
void	free_env(t_env	*node);
char **list_to_env(t_env *node);
char **tokens_to_args(t_token *node);
int	modify_env(t_env *node, char *name, char *content, bool heap);
int	remove_env(t_env *node, char *name);
char *return_env(t_env *node, char *name);
int add_env(t_env *node, char *name, char *content, bool heap);

int bi_cd(const t_token *token, t_env *env_node);
int	bi_echo(const t_token *token);
int bi_env(t_env *env_node);
int bi_exit(bool is_child);
int bi_export(const t_token *token, t_env *env_node);
int	split_env(char *str, char **output1, char **output2);
int bi_pwd(t_env *env_node);
int	bi_unset(const t_token *token, t_env *env_node);
t_env *creat_env(char *name, char *content);
char *return_pwd(t_env *env_node);
int pipeline(void);
t_token *redirect(t_token *first_token, t_heredoc *h_doc, int h_index, int *exit_code);
void	free_token(t_token *token);
void	free_tokens(t_token *token);
void	save_std_fd(void);
void	reset_std_fd(void);
t_token *heredoc(t_token *token, t_heredoc *h_node, unsigned int index, int *exit_code);
int executor(t_token *token, t_env *env_node);


/*define common return codes mostly so malloc failure shuts the program down and isnt treated like other error codes like syntax error*/
#define MALLOC_FAILURE -1
#define SUCCES 0
#define COMMON_FAILURE 1

#define STDIN_CLONE 3
#define STDOUT_CLONE 4

#define ENV_VARIABLE_LENGTH 96

#endif