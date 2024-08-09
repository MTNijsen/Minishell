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
#include <readline/readline.h>
#include <readline/history.h>


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
int executor(t_token *token, t_env *env_node);
int command(t_token *node, t_env *env_node, bool pipe_present , int *pid);
int builtin(t_token *node, t_env *env_node, bool is_child);
int isbuiltin(char *str);
void	free_heredoc(t_heredoc *node);
void wait_exit(int pid, int *exit_code);
t_token *heredoc_receive(t_token *token, t_heredoc *h_doc, unsigned int index, int *exit_code);
t_heredoc *heredoc_read(t_token *token, int *exit_code);


/*define common return codes mostly so malloc failure shuts the program down and isnt treated like other error codes like syntax error*/
#define MALLOC_FAILURE -1
#define SUCCES 0
#define COMMON_FAILURE 1

#define STDIN_CLONE 3
#define STDOUT_CLONE 4

#define ENV_VARIABLE_LENGTH 96

#endif