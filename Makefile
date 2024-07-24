NAME = executor

CC = cc
LIBS = libft/libstdmt.a
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c built_ins/*.c env_funcs_linked_list/*.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re