
NAME = libstdmt.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = char_func/ft_isalnum.c char_func/ft_isalpha.c char_func/ft_isascii.c char_func/ft_isdigit.c char_func/ft_isprint.c char_func/ft_tolower.c char_func/ft_toupper.c \
		mem_func/ft_bzero.c mem_func/ft_calloc.c mem_func/ft_memchr.c mem_func/ft_memcmp.c mem_func/ft_memmove.c mem_func/ft_memset.c \
		num_func/d_to_base_signed.c num_func/d_to_base_unsigned.c num_func/ft_atoi.c num_func/ft_itoa.c \
		str_func/ft_split.c str_func/ft_strappend.c str_func/ft_strchr.c str_func/ft_strdup.c str_func/ft_striteri.c str_func/ft_strjoin.c str_func/ft_strlcat.c str_func/ft_strlcpy.c str_func/ft_strlen.c str_func/ft_strmapi.c str_func/ft_strncmp.c str_func/ft_strndup.c str_func/ft_strnstr.c str_func/ft_strrchr.c str_func/ft_strtrim.c str_func/ft_substr.c str_func/ft_strchr_null.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re