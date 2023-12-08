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
PS_DIR			= ./src/push_swap
CHECKER_DIR		= ./src/checker
INC_DIR			= ./inc
LIBFT_PATH		= ./libft
LIBFT_LIB		= $(LIBFT_PATH)/libft.a
LIBFT_REPO		= https://github.com/mahdemir/libft.git
PULL_LOG		= ./pull_log
PS_HEADER		= $(INC_DIR)/push_swap.h
SUB_DIR	+= checker \
			push_swap
DIRS	:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

SRC = $(addprefix $(PS_DIR)/, \
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
OBJ = $(SRC:$(PS_DIR)/%.c=$(OBJ_DIR)/push_swap/%.o)

BONUS_SRC = $(addprefix $(CHECKER_DIR)/, \
				checker.c \
				checker_utils.c \
				push_bonus.c \
				swap_bonus.c \
				rotate_bonus.c \
				rev_rotate_bonus.c \
				check_arguments_bonus.c)
BONUS_OBJ = $(BONUS_SRC:$(CHECKER_DIR)/%.c=$(OBJ_DIR)/checker/%.o)

##### COMPILATION ##############################################################
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I $(INC_DIR)

SHELL	:= /bin/bash

NAME	= push_swap
CH_NAME = checker
CHECKSUM_FILE := $(BUILD)/last_build_checksum

##### RULES ####################################################################

all: lft $(NAME) bonus
	@if [ -e "$(CHECKSUM_FILE)" ] && [ "$$(cat $(CHECKSUM_FILE))" = "$$(make checksum)" ]; then \
		echo -e "${BOLD}${GREEN}[ OK ]  Push swap & checker are already built!${END}"; \
	else \
		make checksum > "$(CHECKSUM_FILE)"; \
		echo -e "${BOLD}${GREEN}[ OK ]  Push swap & checker built successfully! 🎉${END}"; \
	fi \

$(NAME): $(OBJ) | lft
	@echo -e "${BOLD}${YELLOW}[ .. ]  Compiling push swap..${END}"
	@$(CC) $(CFLAGS) $^ $(LIBFT_LIB) -o $@

$(OBJ_DIR)/push_swap/%.o: $(PS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(IFLAGS)

$(OBJ_DIR):
	@mkdir -p $(BUILD) $(DIRS)

clean:
	@if [ -d "$(LIBFT_PATH)" ]; then \
		make -s clean -C $(LIBFT_PATH); \
	else \
		echo -e "${BOLD}${PURPLE}    > - All objects files have been deleted ❌${END}"; \
	fi
	@rm -rf $(BUILD)

fclean:
	@if [ -d "$(LIBFT_PATH)" ]; then \
		make -s fclean -C $(LIBFT_PATH); \
	else \
		echo -e "${BOLD}${PURPLE}    > - All objects files have been deleted ❌${END}"; \
		echo -e "${BOLD}${RED}    > - Cleaning has been done ❌${END}"; \
	fi
	@rm -rf $(BUILD) $(LIBFT_PATH)
	@rm -f $(NAME) $(CH_NAME) $(PULL_LOG)

re: fclean all

lft:
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		echo -e "${BOLD}${GRAY}    > - Cloning $(LIBFT_REPO) ..${END}\n"; \
		git clone $(LIBFT_REPO) $(LIBFT_PATH) &> /dev/null; \
    else \
        echo -e "${BOLD}${GRAY}    > - Checking for updates in $(LIBFT_REPO) ..${END}"; \
        LOCAL_HASH=$$(git -C $(LIBFT_PATH) rev-parse HEAD); \
        REMOTE_HASH=$$(git -C $(LIBFT_PATH) ls-remote origin -h refs/heads/main | cut -f1); \
        if [ "$$LOCAL_HASH" = "$$REMOTE_HASH" ]; then \
			echo -e "${BOLD}${GRAY}    > - Libft is already up to date!${END}\n"; \
        else \
			echo -e "${BOLD}${GRAY}    > - Updating libft.. See $(PULL_LOG) for details!${END}\n"; \
            git -C $(LIBFT_PATH) pull &> $(PULL_LOG); \
        fi \
    fi
	@make -s -C $(LIBFT_PATH)

bonus: $(CH_NAME)

$(CH_NAME): $(BONUS_OBJ) | lft
	@echo -e "${BOLD}${YELLOW}[ .. ]  Compiling checker..${END}"
	@$(CC) $(CFLAGS) $^ $(LIBFT_LIB) -o $@

$(OBJ_DIR)/checker/%.o: $(CHECKER_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

checksum:
	@find $(SRC_DIR) -name '*.c' | xargs cat ; find $(INC_DIR) -name '*.h' | xargs cat | shasum -a 256 | cut -d ' ' -f 1

.PHONY: all clean fclean re lft bonus
