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

int executor(t_data *data);

int		bi_cd(char **argv, t_data *data);
void	bi_echo(char **argv);
void	bi_env(t_data *data);
void	bi_exit(char **argv, t_data *data, bool pipe_present);
void	bi_export(char **argv, t_data *data);
int		bi_pwd(t_data *data);
void	bi_unset(char **argv, t_data *data);

bool	is_valid_env(char *env_var);
char	**realloc_envp(char **envp, size_t size, size_t *old_size);
int		modify_env_var(t_data *data, char *env_var);
void	remove_env_var(t_data *data, char *name);
char	*return_env_val(char **envp, char *name);



int pipeline(void);
void wait_exit(int pid, int *exit_code);
int	redirect(t_proc *proc);
int heredoc(t_data *data);
void clean_exit(t_data *data, int exit_status);

char *return_pwd(t_data *data);

/*define common return codes mostly so malloc failure shuts the program down and isnt treated like other error codes like syntax error*/
#define MALLOC_FAILURE -1
#define SUCCES 0
#define COMMON_FAILURE 1

#define STDIN_CLONE 3
#define STDOUT_CLONE 4

#define ENV_VARIABLE_LENGTH 96

#endif