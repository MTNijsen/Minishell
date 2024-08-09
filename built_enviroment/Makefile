NAME = executor

CC = cc
LIBS = libstdmt.a -lreadline
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRCS =    built_in_cd.c built_in_echo.c built_in_env.c built_in_exit.c built_in_export.c built_in_pwd.c built_in_unset.c   \
			funcs_free.c funcs_env.c \
			pipeline.c main.c redirect.c heredoc.c exec.c wait.c
 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re