# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 15:37:46 by adaza-ru          #+#    #+#              #
#    Updated: 2026/03/22 23:55:57 by adaza-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = push_swap
BONUS_NAME      = checker

CC              = cc
CFLAGS          = -Wall -Wextra -Werror
RM              = rm -rf

OBJ_DIR         = obj/mandatory
OBJ_DIR_BONUS   = obj/bonus

SRC             = m_main.c m_start_argv_errors.c m_done_and_error.c \
					m_loading_handling.c m_loading_arrays.c m_loading_utils.c \
					m_sorting_m_push.c m_sorting_m_rotate.c m_sorting_m_rr.c \
					m_sorting_m_swap.c m_sorting_handling.c m_sorting_small.c \
					m_sorting_big.c

SRC_BONUS       = b_main_bonus.c b_start_argv_errors_bonus.c \
					b_done_and_error_bonus.c b_loading_handling_bonus.c \
					b_loading_arrays_bonus.c b_loading_utils_bonus.c \
					b_sorting_m_push_bonus.c b_sorting_m_rotate_bonus.c \
					b_sorting_m_rr_bonus.c b_sorting_m_swap_bonus.c \
					b_sorting_handling_bonus.c b_gnl_bonus.c b_gnl_utils_bonus.c

OBJS            = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJS_BONUS      = $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))

all: $(NAME) $(BONUS_NAME)

mandatory: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all mandatory bonus clean fclean re
