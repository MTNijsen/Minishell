typedef struct s_output
{
	char		*node;
	int			type_node;
	s_output	*next_node;
}t_output;

#define COMMAND 1
#define BUILTIN 2
#define FLAG 3
#define FILE 4
#define STRING 5
#define PIPE 6
#define REDIRECT 7
#define ENV_VARIABLE 8
#define LAST_EXIT 9
#define TYPE_NOT_FOUND 0