# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adaza-ru <adaza-ru@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/17 15:37:46 by adaza-ru          #+#    #+#              #
#    Updated: 2026/03/21 20:19:44 by adaza-ru         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -g
RM          = rm -rf

OBJ_DIR     = obj/mandatory

SRC         = main.c start_argv_errors.c done_and_error.c \
              loading_handling.c loading_arrays.c loading_utils.c \
              sorting_m_push.c sorting_m_rotate.c sorting_m_rr.c \
              sorting_m_swap.c sorting_handling.c sorting_small.c \
              sorting_five.c sorting_big.c sorting_utils.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
