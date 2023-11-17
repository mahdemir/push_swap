##### FONT APPEARANCE ##########################################################
END		=$'\033[0m
BOLD	=$'\033[1m
UNDER	=$'\033[4m
REV		=$'\033[7m
GREY	=$'\033[30m
RED		=$'\033[31m
GREEN	=$'\033[32m
YELLOW	=$'\033[33m
BLUE	=$'\033[34m
PURPLE	=$'\033[35m
CYAN	=$'\033[36m
WHITE	=$'\033[37m

##### DIRECTORIES ##############################################################
BUILD			= .build
OBJ_DIR			= $(BUILD)/obj
SRC_DIR			= ./src
INC_DIR			= ./inc
LIBFT_PATH		= ./libft
LIBFT_LIB		= $(LIBFT_PATH)/libft.a
PS_HEADER		= $(INC_DIR)/push_swap.h

SRC = $(addprefix $(SRC_DIR)/, \
    	main.c \
		stack_utils.c \
    	init_stack.c \
		error_handeling.c \
		check_arguments.c \
		push.c \
		swap.c \
		rotate.c \
		rev_rotate.c \
		sort_three.c \
		algorithm.c \
		algorithm_utils.c \
		init_list_a.c \
		init_list_b.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRC = bonus/checker.c \
			bonus/checker_utils.c \
			bonus/push_bonus.c \
			bonus/swap_bonus.c \
			bonus/rotate_bonus.c \
			bonus/rev_rotate_bonus.c \
			bonus/check_arguments_bonus.c \


BONUS_OBJ = $(BONUS_SRC:bonus/%.c=$(OBJ_DIR)/%.o)

##### COMPILATION ##############################################################
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I $(INC_DIR)

SHELL	:= /bin/bash

NAME	= push_swap
BONUS_NAME = checker

##### RULES ####################################################################

all: $(NAME)

$(NAME): $(OBJ) | lft
	@echo -e "${BOLD}${YELLOW}[ .. ] | Compiling push swap..${END}"
	@$(CC) $(CFLAGS) $^ $(LIBFT_LIB) -o $@
	@echo -e "${BOLD}${GREEN}[ OK ] | Compilation is successful! 🎉${END}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(PS_HEADER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -s clean -C $(LIBFT_PATH)
	@rm -rf $(BUILD)
	@echo -e "${BOLD}${RED}> All objects files have been deleted ❌${END}"

fclean: clean
	@make -s fclean -C $(LIBFT_PATH)
	@rm -f $(NAME) $(BONUS_NAME)
	@echo -e "${BOLD}${RED}> Cleaning has been done ❌${END}"

re: fclean all

lft:
	@if [ -f $(LIBFT_LIB) ]; then \
		echo -e "${BOLD}${GREEN}[ OK ] | Libft is already built.${END}"; \
	else \
		make -s -C $(LIBFT_PATH); \
		echo -e "\n${BOLD}${GREEN}[ OK ] | Libft built successfully!${END}"; \
	fi

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) | lft
	@echo -e "${BOLD}${YELLOW}[ .. ] | Compiling checker..${END}"
	@$(CC) $(CFLAGS) $^ $(LIBFT_LIB) -o $@
	@echo -e "${BOLD}${GREEN}[ OK ] | Compilation is successful! 🎉${END}"

$(OBJ_DIR)/%.o: bonus/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re lft bonus
