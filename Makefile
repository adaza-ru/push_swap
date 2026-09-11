# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 15:37:46 by adaza-ru          #+#    #+#              #
#    Updated: 2026/09/11 02:42:07 by adaza-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker
 
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
 
INCLUDE_DIR	= include
SRC_DIR		= src
OBJ_DIR		= obj
 
CPPFLAGS	= -I$(INCLUDE_DIR)
 
COMMON_SRC	= $(SRC_DIR)/common/argv_errors.c \
		  $(SRC_DIR)/common/done_and_error.c \
		  $(SRC_DIR)/common/init_stack.c \
		  $(SRC_DIR)/common/loading_arrays.c \
		  $(SRC_DIR)/common/loading_utils.c \
		  $(SRC_DIR)/common/stack_push_swap.c \
		  $(SRC_DIR)/common/stack_rotations.c \
 
PUSH_SWAP_SRC	= $(SRC_DIR)/push_swap/main.c \
		$(SRC_DIR)/push_swap/decide_sort.c \
		$(SRC_DIR)/push_swap/sorting_handling.c \
		$(SRC_DIR)/push_swap/sorting_small.c \
		$(SRC_DIR)/push_swap/sorting_big.c \
		$(SRC_DIR)/push_swap/ops_push.c \
		$(SRC_DIR)/push_swap/ops_rotations.c \
 
CHECKER_SRC	= $(SRC_DIR)/checker/main.c \
		$(SRC_DIR)/checker/sorting_handling.c \
		$(SRC_DIR)/checker/gnl.c \
		$(SRC_DIR)/checker/gnl_utils.c \
		$(SRC_DIR)/checker/ops_push_swap.c \
		$(SRC_DIR)/checker/ops_push_rotations.c \
 
COMMON_OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(COMMON_SRC))
PUSH_SWAP_OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(PUSH_SWAP_SRC))
CHECKER_OBJS	= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CHECKER_SRC))
 
.PHONY: all mandatory bonus clean fclean re
 
all: $(NAME) $(BONUS_NAME)
 
mandatory: $(NAME)
 
bonus: $(BONUS_NAME)
 
$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PUSH_SWAP_OBJS) -o $(NAME)
 
$(BONUS_NAME): $(COMMON_OBJS) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CHECKER_OBJS) -o $(BONUS_NAME)
 
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
 
clean:
	$(RM) $(OBJ_DIR)
 
fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
 
re: fclean all
 