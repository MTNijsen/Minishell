# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lade-kon <lade-kon@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/06/12 12:11:18 by lade-kon      #+#    #+#                  #
#    Updated: 2024/09/05 17:12:39 by lade-kon      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:=	minishell

CC				:=	cc
#CFLAGS are the compiler flags: show all warnings and include debug info
CFLAGS			:=	-Wall -Werror -Wextra -g #-fsanitize=address
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
SRC_TOKENS		:=	tokens
SRC_PROCS		:=	procs
SRC_ENVIROMENT	:=	enviroment
SRC_UTILS		:=	utils
SRC_BUILT_IN	:=	built_in
SRC_LEXER		:=	lexer
SRC_FILES		:=	main.c \
					input_check.c \
					init_struct.c \
					free_struct.c \
					error.c \
					print_data.c \
					$(addprefix $(SRC_LEXER)/, \
					lexer.c \
					special_tokens.c \
					text_tokens.c \
					utils_tokens.c ) \
					$(addprefix $(SRC_TOKENS)/, \
					create_token.c \
					add_token.c \
					free_tokens.c \
					print_tokens.c \
					last_token.c \
					count_tokens.c ) \
					$(addprefix $(SRC_PROCS)/, \
					init_proc.c \
					create_proc.c \
					add_proc.c \
					add_redir.c \
					print_procs.c \
					free_procs.c \
					last_proc.c \
					count_tokens_proc.c \
					get_procs.c ) \
					$(addprefix $(SRC_EXECUTOR)/, \
					exec.c \
					heredoc.c \
					pipeline.c \
					redirect.c ) \
					$(addprefix $(SRC_ENVIROMENT)/, \
					funcs_env.c ) \
					$(addprefix $(SRC_UTILS)/, \
					exit.c \
					ft_strappend.c \
					ft_strchr_null.c ) \
					$(addprefix $(SRC_BUILT_IN)/, \
					built_in_cd.c \
					built_in_echo.c \
					built_in_env.c \
					built_in_exit.c \
					built_in_export.c \
					built_in_pwd.c \
					built_in_unset.c)

SRC				:=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR			:=	obj
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))


all: $(NAME)

$(LIBFT_A):
	@git submodule update --init --recursive --remote
	@make -C $(LIBFT_DIR) > /dev/null

$(NAME): $(OBJ_DIR) $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(INCLUDES) $(LIBFT_A) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(SRC_PARSER)
	mkdir -p $(OBJ_DIR)/$(SRC_EXECUTOR)
	mkdir -p $(OBJ_DIR)/$(SRC_TOKENS)
	mkdir -p $(OBJ_DIR)/$(SRC_LEXER)
	mkdir -p $(OBJ_DIR)/$(SRC_PROCS)
	mkdir -p $(OBJ_DIR)/$(SRC_ENVIROMENT)
	mkdir -p $(OBJ_DIR)/$(SRC_UTILS)
	mkdir -p $(OBJ_DIR)/$(SRC_BUILT_IN)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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