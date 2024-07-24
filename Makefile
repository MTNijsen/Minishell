# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/06/12 12:11:18 by lade-kon      #+#    #+#                  #
#    Updated: 2024/07/24 19:39:26 by lade-kon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell

CC				:=	cc
#CFLAGS are the compiler flags: show all warnings and include debug info
CFLAGS			:=	-Wall -Werror -Wextra #-g -fsanitize=address
#LDFLAGS are linker flags
LDFLAGS			:=	-lreadline

LIBFT_DIR		:=	lib/libft
LIBFT_A			:=	$(LIBFT_DIR)/libft.a

INCLS_MINISHELL	:=	incl
INCLS_LIBFT		:=	$(LIBFT_DIR)/incl
INCLUDES		:=	-I $(INCLS_MINISHELL) -I $(INCLS_LIBFT)

SRC_DIR			:=	src
SRC_PARSER		:=	parser
SRC_EXECUTOR	:=	executor
SRC_LIST		:=	list
SRC_LEXER		:=	lexer
SRC_DIRS		:=	$(SRC_PARSER) $(SRC_EXECUTOR) $(SRC_LIST) $(SRC_LEXER)
SRC_FILES		:=	$(addprefix $(SRC_DIR)/, \
					main.c) \
					# $(addprefix $(SRC_DIR)/list/, \
					# ft_add_node_back.c \
					# ft_add_node_front.c \
					# ft_clear_list.c \
					# ft_delone_node.c \
					# ft_last_node.c \
					# ft_new_node.c \
					# ft_print_list.c \
					# ft_size_list.c ) \
					# token.c \
					# lexer.c \
					# parser.c \

SRC				:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR			:=	obj
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))


all: $(NAME)

$(LIBFT_A):
	@git submodule update --init --recursive --remote
	@make -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(INCLUDES) $(LIBFT_A) -o $(NAME)

$(OBJ_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(SRC_PARSER)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(SRC_EXECUTOR)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(SRC_LIST)
	mkdir -p $(OBJ_DIR)/$(SRC_DIR)/$(SRC_LEXER)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

norminette:
	@echo "${CYAN}🧐 Checking the Norm...${RESET}"
	@norminette -R CheckForbiddenSourceHeader
	@echo "${GREEN} Norm-i-netting complete. Files are NORM PROOF!${RESET}" 

update:
	@git submodule update --init --recursive --remote

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null

re: fclean all

## Colours ##
RESET	:= \033[0m
RED		:= \033[1;91m
GREEN	:= \033[1;92m
YELLOW	:= \033[1;93m
BLUE	:= \033[1;94m
PURPLE	:= \033[1;95m
CYAN	:= \033[1;96m
WHITE	:= \033[1;97m
BLACK	:= \033[1;90m