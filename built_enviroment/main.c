#include "../minishell.h"

int main(int argc, char **argv, char **env)
{
	t_env *env_node = array_to_list(env);

	t_token *token1 = malloc(sizeof(t_token));
	t_token *token2 = malloc(sizeof(t_token));
	t_token *token3 = malloc(sizeof(t_token));
	t_token *token4 = malloc(sizeof(t_token));
	t_token *token5 = malloc(sizeof(t_token));
	token1->type = TEXT;
	token1->value = ft_strdup("pwd");
	token1->next = token2;
	token2->type = PIPE;
	token2->value = ft_strdup("|");
	token2->next = token3;
	token3->type = TEXT;
	token3->value = ft_strdup("/usr/bin/cat");
	token3->next = token4;
	token4->type = PIPE;
	token4->value = ft_strdup("|");
	token4->next = token5;
	token5->type = TEXT;
	token5->value = ft_strdup("/usr/bin/cat");
	token5->next = NULL;
	save_std_fd();
	int exit_code = executor(token1, env_node);
	printf("%d\n", exit_code);
	(void)argc;
	(void)argv;
	free_env(env_node);
}
